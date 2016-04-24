/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast/nodes/ast_simple_command.h"
#include "shsignal/shsignal.h"
#include "twl_logger.h"
#include <sys/wait.h>
#include "job_control/job.h"

#define SH_PATH_FALLBACK_WHEN_NO_SHEBANG "/bin/sh"

static int			execve_base(char *path, t_lst *argv_lst, char **envp, int *errno_ptr)
{
	char			**argv;
	int				ret;

	argv = (char **)twl_lst_to_arr(argv_lst);
	LOG_INFO("execve: path: %s", path);
	ret = execve(path, argv, envp);
	*errno_ptr = errno;
	twl_arr_del(argv, NULL);
	return (ret);
}

static void			execve_fallback_wrapper(char *path, t_lst *argv_lst, char **envp)
{
	int				errno_save;
	int				ret;

	ret = execve_base(path, argv_lst, envp, &errno_save);
	if (ret == -1 && errno_save == ENOEXEC)
	{
		twl_lst_pop_front(argv_lst);
		twl_lst_push_front(argv_lst, path);
		twl_lst_push_front(argv_lst, SH_PATH_FALLBACK_WHEN_NO_SHEBANG);
		ret = execve_base(SH_PATH_FALLBACK_WHEN_NO_SHEBANG, argv_lst, envp, &errno_save);
	}
	if (ret == -1)
	{
		shenv_singl_error(126, "execve: %s", strerror(errno_save));
	}
}

void				ast_simple_command_execve_child(t_ast_simple_command *cmd, char *path)
{
	char			*cmd_str;
	t_lst			*argv_lst;
	char			**envp;

	argv_lst = token_mgr_to_lst(cmd->cmd_tokens_expanded);
	envp = (char **)shenv_get_env_arr(shenv_singleton());
	job_utils_sigs_dfl_on_interactive_for_chld_proc();
	cmd_str = twl_lst_strjoin(argv_lst, " ");
	LOG_INFO("execve: %s (pid=%d)", cmd_str, getpid());
	execve_fallback_wrapper(path, argv_lst, envp);
	free(cmd_str);
	twl_lst_del(argv_lst, NULL);
	twl_arr_del(envp, free);
	exit(1);
}
