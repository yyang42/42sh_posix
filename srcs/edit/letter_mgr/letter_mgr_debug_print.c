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

static void			print_letter_fn(void *_letter)
{
	t_letter		*letter;

	letter = _letter;
	twl_lprintf("%s", letter->letter);
}

void				letter_mgr_debug_print(t_lst *letters)
{
	twl_lst_iter0(letters, print_letter_fn);
}
