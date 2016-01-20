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

static void			init_ce(char *name, t_class_expr__ *ce)
{
	ce->name = name;
	ce->ind_n = 0;
	ce->ind_e = 0;
	ce->reverse = 0;
	twl_bzero(ce->expr, 128);
	if (ce->name[0] == '^')
	{
		ce->reverse = 1;
		ce->ind_n += 1;
	}
	else if (ce->name[0] == '\\' && ce->name[1] == '^')
	{
		ce->ind_n += 1;
	}
}

static void			reverse_expr(t_class_expr__ *ce)
{
	char			new[128];
	int				ind_n;
	int				ind_e;

	twl_bzero(new, 128);
	ind_n = 1;
	ind_e = 0;
	while (ind_n < 128)
	{
		if (!twl_strchr(ce->expr, ind_n))
		{
			new[ind_e] = ind_n;
			ind_e += 1;
		}
		ind_n += 1;
	}
	twl_strcpy(ce->expr, new);
}

static void			end_ce(t_patmatch *this, t_class_expr__ *ce)
{
	if (twl_strlen(ce->expr) == 0)
	{
		twl_dict_add(this->class_expr, ce->name, NULL);
		return ;
	}
	if (ce->reverse)
		reverse_expr(ce);
	twl_dict_add(this->class_expr, ce->name, twl_strdup(ce->expr));
}

void				patmatch_add_class_expr_(t_patmatch *this, char *name)
{
	t_class_expr__	ce;

	init_ce(name, &ce);
	while (ce.name[ce.ind_n])
	{
		if (ce.name[ce.ind_n + 1] == '-')
			patmatch_ce_hyphen__(&ce);
		else if (ce.name[ce.ind_n] == '[')
			patmatch_ce_open_bracket__(this, &ce);
		else if (!twl_strchr(ce.expr, ce.name[ce.ind_n]))
		{
			ce.expr[ce.ind_e] = ce.name[ce.ind_n];
			ce.ind_e += 1;
		}
		ce.ind_n += 1;
	}
	end_ce(this, &ce);
}
