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

#include "shenv/shenv.h"
#include "ast/nodes/ast_simple_command.h"

static int			execve_base(char *path, t_lst *argv_lst, char **envp,
	int *errno_ptr)
{
	char			**argv;
	int				ret;

	argv = (char **)twl_lst_to_arr(argv_lst);
	LOG_INFO("execve: path: %s", path);
	ast_simple_command_utils_unblock_sigint();
	ret = execve(path, argv, envp);
	ast_simple_command_utils_block_sigint();
	*errno_ptr = errno;
	twl_arr_del(argv, NULL);
	return (ret);
}

static void			execve_fallback_wrapper(char *path, t_lst *argv_lst,
	char **envp)
{
	int				errno_save;
	int				ret;

	ret = execve_base(path, argv_lst, envp, &errno_save);
	if (ret == -1 && errno_save == ENOEXEC)
	{
		twl_lst_pop_front(argv_lst);
		twl_lst_push_front(argv_lst, path);
		twl_lst_push_front(argv_lst, SHENV_SH_PATH_FALLBACK_WHEN_NO_SHEBANG);
		ret = execve_base(SHENV_SH_PATH_FALLBACK_WHEN_NO_SHEBANG, argv_lst,
			envp, &errno_save);
	}
	if (ret == -1)
	{
		shenv_singl_error(126, "execve: %s: %s",
				path, twl_strerror(errno_save));
	}
}

void				shenv_execve(t_shenv *env, char *path, t_lst *argv_lst)
{
	char			*cmd_str;
	char			**envp;

	envp = (char **)shenv_get_env_arr(env);
	cmd_str = twl_lst_strjoin(argv_lst, " ");
	LOG_INFO("execve: %s (pid=%d)", cmd_str, getpid());
	execve_fallback_wrapper(path, argv_lst, envp);
	free(cmd_str);
	twl_arr_del(envp, free);
}
