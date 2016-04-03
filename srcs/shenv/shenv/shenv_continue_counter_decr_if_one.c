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

#include "shenv/shenv.h"

void				shenv_continue_counter_decr_if_one(t_shenv *this)
{
	if (this->shenv_continue_counter == 1)
		this->shenv_continue_counter--;
	if (this->shenv_continue_counter > 0 && this->shenv_loop_level == 1)
		this->shenv_continue_counter = 0;
}
