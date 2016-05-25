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
#include "shenv/shenv.h"

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	if (completion_utils_start_with(((t_shvar *)data)->shvar_key, ctx1))
	{
		LOG_DEBUG("%s", ((t_shvar *)data)->shvar_key);
		twl_lst_push_front(ctx2, ((t_shvar *)data)->shvar_key);
	}
}

void			completion_variable(t_completion *this)
{
	t_lst		*all;
	char		*tmp;

	all = twl_lst_new();
	twl_lst_iter2(shenv_singleton()->shenv_shvars, iter_fn,
				this->current_word, all);
	LOG_DEBUG("Coucou");
	if (twl_lst_len(all) == 1)
	{
		tmp = twl_strjoin(twl_lst_first(all), " ");
		edit_place_string(this->edit, tmp);
		free(tmp);
	}
}
