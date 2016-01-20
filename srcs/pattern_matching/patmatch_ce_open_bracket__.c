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

static void			goto_close_bracket(t_class_expr__ *ce)
{
	char			stop;

	stop = ce->name[ce->ind_n + 1];
	ce->ind_n += 1;
	while (ce->name[ce->ind_n])
	{
		ce->ind_n += 1;
		if (ce->name[ce->ind_n] == stop && ce->name[ce->ind_n + 1] == ']')
			break ;
	}
	if (ce->name[ce->ind_n])
	{
		ce->ind_n += 1;
	}
}

static void			bracket_colon(t_patmatch *this, t_class_expr__ *ce)
{
	int				start;
	char			*key;
	char			*data;
	int				index;

	start = ce->ind_n;
	goto_close_bracket(ce);
	if (!(key = twl_strndup(ce->name + start, ce->ind_n - start + 1)))
		return ;
	if (!(data = twl_dict_get(this->class_expr, key)))
	{
		free(key);
		return ;
	}
	free(key);
	index = 0;
	while (data[index])
	{
		if (!twl_strchr(ce->expr, data[index]))
		{
			ce->expr[ce->ind_e] = data[index];
			ce->ind_e += 1;
		}
		index += 1;
	}
}

void				patmatch_ce_open_bracket__(t_patmatch *this,
															t_class_expr__ *ce)
{
	if (ce->name[ce->ind_n + 1] == '.' || ce->name[ce->ind_n + 1] == '=')
		goto_close_bracket(ce);
	else if (ce->name[ce->ind_n + 1] == ':')
		bracket_colon(this, ce);
	else
	{
		if (!twl_strchr(ce->expr, ce->name[ce->ind_n]))
		{
			ce->expr[ce->ind_e] = ce->name[ce->ind_n];
			ce->ind_e += 1;
		}
	}
}
