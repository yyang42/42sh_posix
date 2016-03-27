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
#include "logger.h"
#include <sys/wait.h>

static void			execve_wrapper(char *path, char **args, char **env)
{
	char			*cmd;

	cmd = twl_strjoinarr((const char **)args, " ");
	LOGGER("execve: %s (pid=%d)", cmd, getpid());
	execve(path, args, env);
	free(cmd);
}

static void			fork_and_execute(char *path, t_lst *tokens, char **env)
{
	pid_t			pid;
	int				res;
	pid_t			waitpid_ret;
	char			**args;

	args = token_mgr_to_str_arr(tokens);
	pid = shenv_utils_fork();

	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{

		// setpgid(0, getpid());

		LOGGER("exec child jc_job_pgid %d", shenv_singleton()->jc_job_pgid);
		LOGGER("exec child getpid()    %d", getpid());
		LOGGER("exec child pid         %d", pid);
		setpgid(getpid(), shenv_singleton()->jc_job_pgid);
		execve_wrapper(path, args, env);
		perror(path);
		exit(0);
	}
	else
	{

		LOGGER("exec jc_job_pgid %d", shenv_singleton()->jc_job_pgid);
		LOGGER("exec getpid()    %d", getpid());
		LOGGER("exec pid         %d", pid);
		setpgid(pid, shenv_singleton()->jc_job_pgid);
		LOGGER("BEFORE WAITPID");
     	waitpid_ret = waitpid(pid, &res, 0);
		LOGGER("AFTER WAITPID");
     	if (waitpid_ret == -1)
     	{
     		perror("waitpid");
     	}
     	else if (waitpid_ret == pid)
     	{
			handle_signal(res);
	    	if (WIFEXITED(res))
	    	{
				shenv_singleton()->last_exit_code = WEXITSTATUS(res);
				LOGGER("exit status: %d", shenv_singleton()->last_exit_code);
	    	}
     	}
	}
	twl_arr_del(args, NULL);
}

void			ast_simple_command_execve(char *path, t_lst *tokens, char **env)
{
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			fork_and_execute(path, tokens, env);
		else
			error_permission_denied(path);
	}
	else
	{
		shenv_print_error_printf(shenv_singleton(),
			token_mgr_first(tokens)->line,
			"%s: %s", token_mgr_first(tokens)->text,
			SHENV_ERROR_COMMAND_NOT_FOUND);
		shenv_singleton()->last_exit_code = EXIT_COMMAND_NOT_FOUND;
	}
}
