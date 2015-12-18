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

static void			bracket_open_dot_equal(t_class_expr__ *toadd)
{
	char		stop;

	stop = toadd->name[toadd->ind_n + 1];
	toadd->ind_n += 2;
	while (toadd->name[toadd->ind_n])
	{
		if (toadd->name[toadd->ind_n] == ']' &&
				toadd->name[toadd->ind_n - 1] == stop)
			break ;
		toadd->ind_n += 1;
	}
	if (toadd->name[toadd->ind_n])
		toadd->ind_n += 1;
}

static void			bracket_open(t_patmatch *this, t_class_expr__ *toadd)
{
	int				save;
	int				index;
	char			*key;
	char			*data;

	save = toadd->ind_n;
	bracket_open_dot_equal(toadd);
	if (!(key = twl_strndup(toadd->name + save, toadd->ind_n - save)))
		return ;
	if (!(data = twl_dict_get(this->class_expr, key)))
	{
		free(key);
		return ;
	}
	free(key);
	index = -1;
	while (data[++index])
	{
		if (!twl_strchr(toadd->expr, data[index]))
		{
			toadd->expr[toadd->ind_e] = data[index];
			toadd->ind_e += 1;
		}
	}
}

static void			bracket_open(t_patmatch *this, t_class_expr__ *toadd)
{
	if (toadd->name[toadd->ind_n] == '.' || toadd->name[toadd->ind_n] == '=')
		bracket_open_dot_equal(toadd);
	else if (toadd->name[toadd->ind_n] == ':')
		bracked_open_expr(this, toadd);
	else if (!twl_strchr(toadd->expr, toadd->name[toadd->ind_n]))
	{
		toadd->expr[toadd->ind_e] = data[index];
		toadd->ind_e += 1;
	}

}

void				patmatch_add_class_expr_(t_patmatch *this, char *content)
{
	t_class_expr__	toadd;

	toadd.name = content;
	toadd.ind_n = 0;
	toadd.ind_e = 0;
	twl_bzero(toadd__.expr, 128);
	while (toadd.name[toadd.ind_n])
	{
		if (toadd.name[toadd.ind_n] == '[')
			bracket_open(this, &toadd);
		else if (!twl_strchr(toadd.expr, toadd.name[toadd.ind_n]))
		{
			toadd.expr[toadd.ind_e] = data[index];
			toadd.ind_e += 1;
		}
	}
	twl_dict_add(this->class_expr, content, twl_strdup(toadd.expr));
}
