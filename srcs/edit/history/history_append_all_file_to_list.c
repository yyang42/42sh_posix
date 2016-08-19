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

#include "edit/history.h"

static void		iter_fn(void *data, void *ctx)
{
	history_push(ctx, line_new_from_string(data));
}

void			history_append_all_file_to_list(t_history *this, char *path)
{
	t_lst		*content;

	if (!(content = history_utils_get_histfile(path)))
		return ;
	twl_lst_iter(content, iter_fn, this);
	twl_lst_del(this->save, free);
	this->save = content;
}
