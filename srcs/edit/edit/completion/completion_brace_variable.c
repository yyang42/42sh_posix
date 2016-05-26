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
		twl_lst_push_front(ctx2, ((t_shvar *)data)->shvar_key);
	}
}

void			completion_brace_variable(t_completion *this)
{
	t_lst		*all;
	char		*tmp;

	all = twl_lst_new();
	twl_lst_iter2(shenv_singleton()->shenv_shvars, iter_fn,
				this->current_word, all);
	if (!twl_lst_first(all))
		;
	else if (twl_lst_len(all) == 1)
	{
		tmp = twl_strjoin(twl_lst_first(all) + twl_strlen(this->current_word), "} ");
		edit_place_string(this->edit, tmp);
		free(tmp);
	}
	else if ((tmp = completion_utils_get_begin_list(this, all)))
	{
		edit_place_string(this->edit, tmp);
		free(tmp);
	}
	else
	{
		if (this->edit->is_last_tab)
			completion_utils_print_lst(this, all);
		this->edit->is_last_tab = 2;
	}
	twl_lst_del(all, NULL);
}
