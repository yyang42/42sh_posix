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
#include "job_control/jobexec.h"

static void			job_execve_fn(void *tokens)
{
	char			*path;

	path = shenv_find_binary_path(shenv_singleton(), twl_lst_first(tokens));
	if (path)
		shenv_execve(shenv_singleton(), path, tokens);
	else
		LOG_ERROR("path not found");
}

static void			wait_fn(int pid, void *ctx)
{
	LOG_INFO("ast_simple_command_execve wait_fn");
	job_utils_waitpid(pid);
	(void)pid;
	(void)ctx;
}

static void			jobexec_fork_exec_wrapper(t_lst *all_tokens, t_lst *cmd_tokens)
{
	t_jobexec		je;

	je.all_tokens = all_tokens;
	je.exec_ctx = cmd_tokens;
	je.wait_fn = wait_fn;
	je.execve_fn = job_execve_fn;
	jobexec_fork_exec(&je);
}

void				ast_simple_command_execve(t_lst *cmd_tokens, t_lst *all_tokens)
{
	char			*path;
	char			*cmd_name;

	cmd_name = twl_lst_first(cmd_tokens);
	path = shenv_find_binary_path(shenv_singleton(), cmd_name);
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			jobexec_fork_exec_wrapper(all_tokens, cmd_tokens);
		else
			error_permission_denied(path);
	}
	else
	{
		shenv_singl_error(EXIT_COMMAND_NOT_FOUND, "%s: %s", cmd_name,
			SHENV_ERROR_COMMAND_NOT_FOUND);
		LOG_INFO("%s: %s", cmd_name, SHENV_ERROR_COMMAND_NOT_FOUND);
	}
}
