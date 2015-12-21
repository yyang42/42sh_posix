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

#include <patmatch.h>

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
	{
		free(key);
		return ;
	}
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

static void			open_bracket(t_patmatch *this, t_class_expr__ *ce)
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

static void			hyphen_check(t_class_expr__ *ce)
{
	char			beg;
	char			end;

	beg = ce->name[ce->ind_n];
	end = ce->name[ce->ind_n + 2];
	if (ce->ind_n + 2 == (int)twl_strlen(ce->name))
	{
		if (!twl_strchr(ce->expr, ce->name[ce->ind_n]))
		{
			ce->expr[ce->ind_e] = ce->name[ce->ind_n];
			ce->ind_e += 1;
		}
		return ;
	}
	while (beg <= end)
	{
		if (!twl_strchr(ce->expr, beg))
		{
			ce->expr[ce->ind_e] = beg;
			ce->ind_e += 1;
		}
		beg += 1;
	}
	ce->ind_n += 2;
}

void				patmatch_add_class_expr_(t_patmatch *this, char *name)
{
	t_class_expr__	ce;

	init_ce(name, &ce);
	while (ce.name[ce.ind_n])
	{
		if (ce.name[ce.ind_n + 1] == '-')
			hyphen_check(&ce);
		else if (ce.name[ce.ind_n] == '[')
			open_bracket(this, &ce);
		else if (!twl_strchr(ce.expr, ce.name[ce.ind_n]))
		{
			ce.expr[ce.ind_e] = ce.name[ce.ind_n];
			ce.ind_e += 1;
		}
		ce.ind_n += 1;
	}
	end_ce(this, &ce);
}
