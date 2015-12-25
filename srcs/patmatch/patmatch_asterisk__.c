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

int				patmatch_asterisk__(t_patmatch *this, t_match__ *m)
{
	int				ret;
	int				len;

	len = m->len - m->ind_n;
	while (len >= 0)
	{
		m->ind_n += len;
		m->ind_p += 1;
		if ((ret = patmatch_supervisor__(this, m)))
		{
			m->ind_n -= len;
			m->ind_p -= 1;
			return (ret);
		}
		m->ind_n -= len;
		m->ind_p -= 1;
		len -= 1;
	}
	return (0);
}
