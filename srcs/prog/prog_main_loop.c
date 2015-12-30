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

#include "prog.h"
#include "edit/edit.h"

static char			*get_cmd(void)
{
	t_edit			*edit;
	char 			*cmd;

	edit = edit_new();
	cmd = edit_loop(edit);
	edit_del(edit);
	return (cmd);
}

void				prog_main_loop(t_prog *prog, t_environment *env)
{
	char			*cmd;

	while (1)
	{
		cmd = get_cmd();
		// Do your job with the CMD ^^
		/*
		** Simple exit for test. Remove when handle exit cmd
		*/
		if (twl_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			prog_del(prog);
			exit(0);
		}
		free(cmd);
	}
	(void)prog;
	(void)env;
}
