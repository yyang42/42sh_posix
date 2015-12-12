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

static void		harmonize_cpy_push(t_pattern_harmonize_ *harm, int *index)
{
	t_pattern_data		*cpy;

	cpy = (t_pattern_data *)malloc(sizeof(t_pattern_data));
	cpy->split = twl_strdup(harm->data->split);
	cpy->fixed = harm->data->fixed;
	twl_lst_push(harm->to_push, cpy);
	*index += 1;
}

static void		harmonize_sub(t_pattern_harmonize_ *harm, int val)
{
	t_pattern_data		*cpy;
	int					len;

	len = harm->index - harm->start + val;
	if (len == 0)
		return ;
	cpy = (t_pattern_data *)malloc(sizeof(t_pattern_data));
	cpy->split = twl_strsub(harm->data->split, harm->start, len);
	cpy->fixed = harm->data->fixed;
	twl_lst_push(harm->to_push, cpy);
}

static void		skip_slash(t_pattern_harmonize_ *harm, int flag)
{
	if (flag == 0)
	{
		while (harm->data->split[harm->index] == '/')
		{
			harm->index += 1;
		}
		harm->flag = 0;
	}
	else
	{
		while (harm->data->split[harm->index] == '/')
		{
			harm->index += 1;
		}
		harm->start = harm->index;
		harm->index -= 1;
	}
}

static void		harmonize_loop(t_pattern *this, t_pattern_harmonize_ *harm,
																	int *index)
{
	while ((harm->data = twl_lst_get(this->split, *index)))
	{
		harm->index = 0;
		if (harm->flag == 1)
			skip_slash(harm, 0);
		if (harm->data->fixed == false)
		{
			harmonize_cpy_push(harm, index);
			continue ;
		}
		harm->start = harm->index;
		while (harm->data->split[harm->index])
		{
			if (harm->data->split[harm->index] == '/')
			{
				harmonize_sub(harm, 0);
				twl_lst_push(this->harm_, harm->to_push);
				harm->to_push = twl_lst_new();
				skip_slash(harm, 1);
			}
			harm->index += 1;
		}
		harmonize_sub(harm, 0);
		*index += 1;
	}
}

void			pattern_build_harmonize_(t_pattern *this)
{
	t_pattern_harmonize_	harm;
	int						index;

	this->harm_ = twl_lst_new();
	index = 0;
	harm.to_push = twl_lst_new();
	harm.index = 0;
	harm.flag = (pattern_get_begin_file(this) == '/') ? 1 : 0;
	harmonize_loop(this, &harm, &index);
	if (twl_lst_len(harm.to_push) == 0)
		twl_lst_del(harm.to_push, &free);
	else
		twl_lst_push(this->harm_, harm.to_push);
}
