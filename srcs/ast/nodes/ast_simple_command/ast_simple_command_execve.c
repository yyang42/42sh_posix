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
static void			fork_and_execute(t_ast_simple_command *cmd, char *path)
{
	pid_t			pid;


	pid = shenv_utils_fork();
	if (pid == -1)
	{
		shenv_singl_error(2, "cannot fork: %s", strerror(errno));
		LOG_ERROR("cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		setpgid(getpid(), getpid());
		set_default_signal_if_not_ignored();
		ast_simple_command_execve_child(cmd, path);
	}
	else
	{
		ast_simple_command_execve_parent(cmd, pid);
	}
}

void			ast_simple_command_execve(t_ast_simple_command *cmd, char *cmd_name)
{
	char			*path;

	path = shenv_find_binary_path(shenv_singleton(), cmd_name);
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			fork_and_execute(cmd, path);
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
