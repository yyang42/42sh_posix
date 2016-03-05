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
#include "ast/ast.h"
#include "edit/edit.h"

static char			*get_cmd(void)
{
	t_edit			*edit;
	char 			*cmd;

	edit = edit_new();
	cmd = edit_loop(edit);
	if (twl_strcmp(cmd, "history") == 0)
	{
		history_mgr_print(edit->history->history);
	}
	history_mgr_add(edit->history->history, cmd);
	edit_del(edit);
	return (cmd);
}

void				prog_main_loop(t_prog *prog)
{
	char			*input;

	while (1)
	{
		input = get_cmd();
		if (twl_strequ(input, "exit"))
		{
			free(input);
			exit(0);
		}
		ast_exec_string(input);;
		free(input);
	}
	(void)prog;
}
