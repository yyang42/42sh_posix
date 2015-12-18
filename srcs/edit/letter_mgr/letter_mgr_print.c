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

#include "edit/letter_mgr.h"
#include "edit/terminal.h"

static void			print_letter_fn(void *_letter, int index, void *_cursor_index)
{
	t_letter		*letter;
	int				cursor_index;

	letter = _letter;
	cursor_index = *((int *)_cursor_index);
	if (index == cursor_index)
		terminal_radio_letter();
	twl_putstr(letter->letter);
	terminal_clear_letter();
	// twl_lprintf("cursor_index: %d\n", cursor_index);
}

void				letter_mgr_print(t_lst *letters, int index)
{
	twl_lst_iteri(letters, print_letter_fn, &index);
}
