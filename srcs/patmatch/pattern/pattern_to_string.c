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

#include "pattern.h"

static void			iter_to_string(void *data_, void *ret_)
{
	t_pattern_data	*data;
	char			**ret;

	data = data_;
	ret = ret_;
	*ret = twl_strjoinfree(*ret, data->split, 'l');
}

char				*pattern_to_string(t_pattern *this)
{
	char			*ret;

	ret = twl_strdup("");
	twl_lst_iter(this->split, &iter_to_string, &ret);
	return (ret);
}
