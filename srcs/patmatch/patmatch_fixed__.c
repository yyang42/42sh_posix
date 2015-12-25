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

#include "patmatch.h"

int					patmatch_fixed__(t_patmatch *this, t_match__ *m,
														t_pattern_data *data)
{
	size_t			len;
	int				ret;

	len = twl_strlen(data->split);
	ret = 0;
	if (!twl_memcmp(m->name + m->ind_n, data->split, len))
	{
		m->ind_n += len;
		m->ind_p += 1;
		ret = patmatch_supervisor__(this, m);
		m->ind_n -= len;
		m->ind_p -= 1;
	}
	return (ret);
}
