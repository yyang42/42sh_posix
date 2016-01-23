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

static void		*map_fn(void *data_)
{
	t_pattern_substr_data	*data;
	t_pattern_substr_data	*new;

	data = data_;
	new = twl_malloc_x0(sizeof(t_pattern_substr_data));
	if (data->fixed)
		new->piece = twl_strrev(twl_strdup(data->piece));
	else
		new->piece = twl_strdup(data->piece);
	new->fixed = data->fixed;
	return (new);
}

void			pattern_substr_rev(t_pattern_substr *this)
{
	t_lst		*new;

	new = twl_lst_map(this->split, &map_fn);
	twl_lst_rev(new);
	twl_lst_del(this->split, &del_pattern_data_fn);
	this->split = new;
}
