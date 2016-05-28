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

void			completion_exec_from_root(t_completion *this)
{
	t_completion_path	path;
	char				*tmp;
	LOG_DEBUG("From root");

	completion_path_init(&path, this);
	completion_path_exec_readfile(this, &path);
	if (!twl_lst_first(this->all))
		;
	else if (twl_lst_len(this->all) == 1)
	{
		edit_place_string(this->edit, twl_lst_first(this->all) + twl_strlen(path.end));
	}
	else if ((tmp = completion_path_utils_get_begin_list(this, &path)))
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
	twl_lst_clear(this->all, free);
	completion_path_clear(&path);
}
