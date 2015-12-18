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
#include "edit/terminal.h"

static void			print_letter_fn(void *_letter, int index, void *_edit)
{
	t_letter		*letter;
	t_edit			*edit;

	letter = _letter;
	edit = _edit;
	twl_lprintf("ret: %d\n", edit->return_cmd);
	if (!edit->return_cmd && index == edit->index)
	{
		twl_lprintf("in");
		terminal_radio_letter();
	}
	twl_putstr(letter->letter);
	terminal_clear_letter();
}

void				edit_print_letters(t_edit *this)
{
	terminal_delete_line();
	terminal_carriage_return();
	twl_lst_iteri(this->letters, print_letter_fn, this);
	if (this->return_cmd)
		write(1, "\n", 1);
}
