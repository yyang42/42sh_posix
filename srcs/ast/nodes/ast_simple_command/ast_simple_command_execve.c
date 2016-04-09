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
#include "trap/trap_mgr.h"
#include <sys/wait.h>

static void			set_default_signal_if_not_ignored(void)
{
	int				i;
	sig_t			saved;

	i = 0;
	while (i < 32)
	{
		saved = signal(i, SIG_DFL);
		if (saved == SIG_IGN)
			signal(i, SIG_IGN);
		i++;
	}
}
static void			fork_and_execute(t_ast_simple_command *cmd, char *path, char **env)
{
	pid_t			pid;
	char			**args;

	args = token_mgr_to_str_arr(cmd->command_tokens_expanded);
	pid = shenv_utils_fork();
	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		set_default_signal_if_not_ignored();
		ast_simple_command_execve_child(path, args, env);
		perror(path);
		exit(0);
	}
	else
	{
		ast_simple_command_execve_parent(cmd, pid);
	}
	twl_arr_del(args, NULL);
}

void			ast_simple_command_execve(t_ast_simple_command *cmd, char *path, char **env)
{
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			fork_and_execute(cmd, path, env);
		else
			error_permission_denied(path);
	}
	else
	{
		shenv_print_error_printf(shenv_singleton(),
			token_mgr_first(cmd->command_tokens_expanded)->line,
			"%s: %s", token_mgr_first(cmd->command_tokens_expanded)->text,
			SHENV_ERROR_COMMAND_NOT_FOUND);
		shenv_singleton()->last_exit_code = EXIT_COMMAND_NOT_FOUND;
	}
}
