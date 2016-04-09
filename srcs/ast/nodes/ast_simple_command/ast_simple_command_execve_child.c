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
#include "job_control/job.h"

void				ast_simple_command_execve_child(char *path, char **args, char **env)
{
	char			*cmd;

	job_utils_sigs_dfl_on_interactive_for_chld_proc();
	cmd = twl_strjoinarr((const char **)args, " ");
	LOGGER_INFO("execve: %s (pid=%d)", cmd, getpid());
	execve(path, args, env);
	free(cmd);
}
