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
	LOG_DEBUG("simple cmd wait_fn called");
	job_utils_waitpid(pid);
	(void)pid;
	(void)ctx;
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
			jobexec_fork_exec(all_tokens, cmd_tokens, wait_fn, job_execve_fn);
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
