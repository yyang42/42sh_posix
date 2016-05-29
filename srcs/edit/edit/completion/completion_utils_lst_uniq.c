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

#include "edit/completion.h"

static bool		cmp_fn(void *ctx1, void *ctx2)
{
	return (twl_strcmp(ctx1, ctx2) > 0);
}

void			completion_utils_lst_uniq(t_completion *this)
{
	t_lst		*cpy;
	char		*current;
	char		*last;

	twl_lst_qsort(this->all, cmp_fn);
	cpy = twl_lst_new();
	last = NULL;
	this->all_len = 0;
	while ((current = twl_lst_pop_front(this->all)))
	{
		if (!last || twl_strcmp(last, current))
		{
			twl_lst_push_front(cpy, current);
			this->all_len += 1;
		}
		last = current;
	}
	twl_lst_del(this->all, NULL);
	this->all = cpy;
}
