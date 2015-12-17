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

void				letter_mgr_remove(t_lst *letters, t_letter *letter)
{
	int				index;

	index = twl_lst_indexof(letters, letter);
	if (index == -1)
	{
		assert(!"[ERROR] Object not found!");
	}
	twl_lst_popi(letters, index);
	letter_del(letter);
}
