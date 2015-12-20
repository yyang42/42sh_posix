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
	edit = edit_new();
	while (1)
	{
		// Do your job with the CMD ^^
		cmd = edit_loop(edit);
	}
	(void)cmd;
	edit_del(edit);
	(void)prog;
	(void)env;
}
