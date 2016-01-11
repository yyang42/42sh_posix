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

#include "edit/edit.h"

static void			print_fn(void *_letter)
{
	t_letter		*letter;

	letter = _letter;
	twl_lprintf("%s", letter->letter);
}

void				edit_debug_print(t_edit *this)
{
	// twl_lprintf("index: %d\n", this->index);
	// twl_lprintf("return cmd: %d\n", this->return_cmd);
	// twl_lprintf("letters : ");
	// twl_lst_iter0(this->letters, print_fn);
	// twl_lprintf("\n");
	(void)this;
	(void)print_fn;
}
