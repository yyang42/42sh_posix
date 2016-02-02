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

#include "pattern_matching/pattern_substr.h"

static void		del_pattern_data_fn(void *data_)
{
	t_pattern_substr_data	*data;

	data = data_;
	free(data->piece);
	free(data);
}

void			pattern_substr_del(t_pattern_substr *this)
{
	twl_lst_del(this->split, &del_pattern_data_fn);
	free(this->pattern);
	free(this);
}
