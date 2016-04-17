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

#include "pattern_matching/pattern.h"

static void			iter_create_num_slash_fn(void *d, void *ctx1, void *ctx2)
{
	t_pattern_data	*data;
	t_pattern		*this;
	size_t			*index;
	size_t			data_index;

	data = d;
	this = ctx1;
	index = ctx2;
	data_index = 0;
	while (data->split[data_index])
	{
		if (data->split[data_index] == '/')
			this->num_slash[*index] += 1;
		else if (data_index > 0 && data->split[data_index - 1] == '/')
			*index += 1;
		data_index += 1;
	}
	if (data->split[data_index - 1] == '/')
		*index += 1;
}

void				pattern_build_num_slash_(t_pattern *this)
{
	size_t			index;

	this->tot_num_slash = (pattern_get_depth(this) +
			((pattern_get_begin_file(this) == '/') ? 1 : 0) + 1);
	this->num_slash = twl_malloc_x0(sizeof(int) * this->tot_num_slash);
	index = 0;
	twl_lst_iter2(this->split, iter_create_num_slash_fn, this, &index);
}
