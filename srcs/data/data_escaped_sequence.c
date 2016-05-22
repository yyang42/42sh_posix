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

#include "data.h"
#include "edit/escaped_sequence.h"

t_lst				*data_escaped_sequence(void)
{
	t_lst			*data = NULL;

	if (!data)
	{
		data = twl_lst_new();
		twl_lst_push_front(data, escaped_sequence_new("\033[C", edit_move_right));
		twl_lst_push_front(data, escaped_sequence_new("\033[D", edit_move_left));
	}
	return (data);
}
