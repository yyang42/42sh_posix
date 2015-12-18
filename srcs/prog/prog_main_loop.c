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
#include "edit.h"


#include "twl_printf.h"

void				prog_main_loop(t_prog *prog, t_environment *env)
{
	(void)prog;
	(void)env;

	t_edit			*edit;

	edit = edit_new();
	while (1){
		edit_loop(edit);
	}
	edit_del(edit);
}
