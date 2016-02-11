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

#include "expan/expan_exec.h"
#include "expan/expan_command.h"
#include "prog.h"
#include <stdio.h>
#include <fcntl.h>

static void		expan_exec_execute(char *command)
{
	t_prog			*prog;

	prog = prog_new();
	prog_run_input(prog, command);
	prog_del(prog);
}

bool			expan_exec_command(t_expan_token *expan_token)
{
	t_expan_command	*expan_command;
	char			buffer[CMD_MAX_LEN + 1];
	int				out_pipe[2];
	int				saved_stdout;
	long			flags;

	expan_command = expan_token->expan_data;
	twl_bzero(buffer, CMD_MAX_LEN + 1);
	saved_stdout = dup(STDOUT_FILENO);
	if(pipe(out_pipe) != 0)
		return (false);
	flags = fcntl(out_pipe[0], F_GETFL);
	flags |= O_NONBLOCK;
	fcntl(out_pipe[0], F_SETFL, flags);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	expan_exec_execute(expan_command->command);
	read(out_pipe[0], buffer, CMD_MAX_LEN);
	close(out_pipe[0]);
	dup2(saved_stdout, STDOUT_FILENO);
	expan_token->res = twl_strdup(buffer);
	return (true);
}
