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

static void		iter_fn(void *data, void *ctx)
{
	if (completion_utils_start_with(((t_shvar *)data)->shvar_key,
				((t_completion *)ctx)->current_word))
	{
		twl_lst_push_front(((t_completion *)ctx)->all,
				((t_shvar *)data)->shvar_key);
		((t_completion *)ctx)->all_len += 1;
	}
}

void			completion_brace_variable(t_completion *this)
{
	char		*tmp;

	twl_lst_iter(shenv_singleton()->shenv_shvars, iter_fn, this);
	if (!twl_lst_first(this->all))
		;
	else if (this->all_len == 1)
	{
		tmp = twl_strjoin(twl_lst_first(this->all) + twl_strlen(this->current_word), "} ");
		edit_place_string(this->edit, tmp);
		free(tmp);
	}
	else if ((tmp = completion_utils_get_begin_list(this)))
	{
		edit_place_string(this->edit, tmp);
		free(tmp);
	}
	else
	{
		if (this->edit->is_last_tab)
			completion_utils_print_lst(this);
		this->edit->is_last_tab = 2;
	}
}
