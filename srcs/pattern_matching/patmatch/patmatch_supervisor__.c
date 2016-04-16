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

#include "pattern_matching/patmatch.h"

static int			match_is_end(t_patmatch *this, t_match__ *m)
{
	if (m->name[m->ind_n] == 0)
		return (1);
	return (0);
	(void)this;
}

int					patmatch_supervisor__(t_patmatch *this, t_match__ *m)
{
	t_pattern_data	*data;
	int				ret;

	data = twl_lst_get(m->pattern, m->ind_p);
	ret = 0;
	if (!data)
		return (match_is_end(this, m));
	LOGGER_DEBUG("\033[31;1m%s\033[0m", data->split)
	if (m->name[m->ind_n] == 0 && (!data->fixed && data->split[0] == '*'))
	{
		m->ind_p += 1;
		ret = patmatch_supervisor__(this, m);
		m->ind_p -= 1;
	}
	else if (m->name[m->ind_n] == 0)
		ret = 0;
	else if (data->fixed)
		ret = (patmatch_fixed__(this, m, data));
	else if (data->split[0] == '?')
		ret = (patmatch_question_mark__(this, m));
	else if (data->split[0] == '*')
		ret = (patmatch_asterisk__(this, m));
	else if (data->split[0] == '[')
		ret = (patmatch_bracket__(this, m, data));
	return (ret);
}
