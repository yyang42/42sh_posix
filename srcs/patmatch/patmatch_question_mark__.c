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

int				patmatch_question_mark__(t_patmatch *this, t_match__ *m)
{
	int				ret;

	if (m->name[m->ind_n] == 0)
		return (0);
	m->ind_n += 1;
	m->ind_p += 1;
	ret = patmatch_supervisor__(this, m);
	m->ind_n -= 1;
	m->ind_p -= 1;
	return (ret);
}
