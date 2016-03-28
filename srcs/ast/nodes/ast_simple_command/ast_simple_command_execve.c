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

static void			fork_and_execute(char *path, t_lst *tokens, char **env)
{
	pid_t			pid;
	char			**args;

	args = token_mgr_to_str_arr(tokens);
	pid = shenv_utils_fork();

	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		ast_simple_command_execve_child(path, args, env);
		perror(path);
		exit(0);
	}
	else
	{
		ast_simple_command_execve_parent(tokens, pid);
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
