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

static void			del_pattern_data(void *data_)
{
	t_pattern_data	*data;

	data = data_;
	free(data->split);
	free(data);
}

static void			del_harmonize(void *data_)
{
	t_lst			*data;

	data = data_;
	twl_lst_del(data, del_pattern_data);
}

void				pattern_del(t_pattern *this)
{
	if (!this)
		return ;
	if (this->split)
		twl_lst_del(this->split, &del_pattern_data);
	if (this->harm_)
		twl_lst_del(this->harm_, &del_harmonize);
	if (this->pattern)
		free(this->pattern);
	free(this);
}
