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

#include "letter_mgr.h"

static void			print_letter_fn(void *letter_)
{
	t_letter	*letter;

	letter = letter_;
	twl_printf("<Object #%p>\n", letter);
}

void				letter_mgr_print(t_lst *letters)
{
	twl_printf("%s>>>>>>>>>> letter list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(letters, print_letter_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
