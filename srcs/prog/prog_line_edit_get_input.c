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

//#include "prog.h"
//#include "edit/edit.h"
//#include "job_control/job_mgr.h"
//
//static char			*get_cmd(void)
//{
//	t_edit			*edit;
//	char 			*cmd;
//
//	edit = edit_new();
//	cmd = edit_loop(edit);
//	if (twl_strcmp(cmd, "history") == 0)
//	{
//		history_mgr_print(edit->history->history);
//	}
//	history_mgr_add(edit->history->history, cmd);
//	edit_del(edit);
//	return (cmd);
//}
//
//void				handle_verbose(char *input)
//{
//	if (shenv_shflag_exist(shenv_singleton(), "verbose"))
//	{
//		twl_putstr_fd(input, 2);
//		twl_putstr_fd("\n", 2);
//	}
//}
//
//char				*prog_line_edit_get_input(t_prog *prog)
//{
//	char			*input;
//
//	input = get_cmd();
//	handle_verbose(input);
//	return (input);
//	(void)prog;
//}

#include "prog.h"
#include "job_control/job_mgr.h"
#include "edit/edit.h"

char				*prog_line_edit_get_input(t_prog *prog)
{
//	char			*input;
//
//	input = get_cmd();
//	handle_verbose(input);
//	return (input);
//	(void)prog;
	return (edit_get_line(edit_singleton()));
	(void)prog;
}
