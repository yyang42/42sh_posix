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

#include "basics.h"
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_command.h"
#include "prog.h"
#include <stdio.h>

bool			expan_exec_command(t_expan_token *expan_token)
{
	t_expan_command	*expan_command;
	char			buffer[CMD_MAX_LEN + 1];
	int				out_pipe[2];
	int				saved_stdout;
	t_prog			*prog;

	expan_command = expan_token->expan_data;
	prog = prog_new();
	twl_bzero(buffer, CMD_MAX_LEN + 1);
	saved_stdout = dup(STDOUT_FILENO);
	if(pipe(out_pipe) != 0)
		return (false);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	prog_run_input(prog, expan_command->command);
	read(out_pipe[0], buffer, CMD_MAX_LEN);
	dup2(saved_stdout, STDOUT_FILENO);
	expan_token->res = twl_strdup(buffer);
	prog_del(prog);
	return (true);
}
