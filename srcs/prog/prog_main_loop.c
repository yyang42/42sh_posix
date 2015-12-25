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

void				prog_main_loop(t_prog *prog, t_environment *env)
{

	t_edit			*edit;
	char			*cmd;
	/*
	** TODO: how delete exit when we exit of shell ?
	*/
	while (1)
	{
		// Do your job with the CMD ^^
		edit = edit_new();
		cmd = edit_loop(edit);
		/*
		** Simple exit for test. Remove when handle exit cmd
		*/
		edit_del(edit);
		if (twl_strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			prog_del(prog);
			exit(0);
		}
	}
	(void)prog;
	(void)env;
}
