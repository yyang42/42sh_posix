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

#include "edit/copast.h"

void				copast_is_selected_index(t_copast *this, int letter_index, int cur_index)
{
	if (this != NULL && !this->has_copy)
	{
		if (cur_index > letter_index && letter_index >= this->start_index)
			twl_putstr(C_YELLOW);
		if (cur_index < letter_index && letter_index <= this->start_index)
			twl_putstr(C_YELLOW);
	}
	if (this != NULL && this->has_copy)
	{
		if (letter_index > this->start_index && letter_index < this->stop_index)
			twl_putstr(C_RED);
		if (letter_index < this->start_index && letter_index > this->stop_index)
			twl_putstr(C_RED);
	}
}
