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

static void			goto_close_bracket(t_brackexpr_find_ *bef)
{
	char			stop;

	stop = bef->expr[bef->ind_e + 1];
	bef->ind_e += 1;
	while (bef->expr[bef->ind_e])
	{
		bef->ind_e += 1;
		if (bef->expr[bef->ind_e] == stop && bef->expr[bef->ind_e + 1] == ']')
			break ;
	}
	if (bef->expr[bef->ind_e])
	{
		bef->ind_e += 1;
	}
}

static void			bracket_colon(t_bracket_expr *this, t_brackexpr_find_ *bef)
{
	int				start;
	char			*key;
	char			*data;
	int				index;

	start = bef->ind_e;
	goto_close_bracket(bef);
	if (!(key = twl_strndup(bef->expr + start, bef->ind_e - start + 1)))
		return ;
	if (!(data = twl_dict_get(this->dict, key)))
	{
		free(key);
		return ;
	}
	free(key);
	index = 0;
	while (data[index])
	{
		if (!twl_strchr(bef->ret, data[index]))
		{
			bef->ret[bef->ind_r] = data[index];
			bef->ind_r += 1;
		}
		index += 1;
	}
}

void				bracket_expr_find_bracket_(t_bracket_expr *this,
														t_brackexpr_find_*bef)
{
	if (bef->expr[bef->ind_e + 1] == '.' || bef->expr[bef->ind_e + 1] == '=')
		goto_close_bracket(bef);
	else if (bef->expr[bef->ind_e + 1] == ':')
		bracket_colon(this, bef);
	else if (!twl_strchr(bef->ret, bef->expr[bef->ind_e]))
	{
		bef->ret[bef->ind_r] = bef->expr[bef->ind_e];
		bef->ind_r += 1;
	}
}
