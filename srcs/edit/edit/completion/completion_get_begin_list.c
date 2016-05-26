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

static void		iter_fn(void *data, void *ctx)
{
	if (!*(char *)ctx)
		return ;
	while (*(char *)ctx && *(char *)data == *(char *)ctx)
	{
		data += 1;
		ctx += 1;
	}
	*(char *)ctx = 0;
}

char			*completion_utils_get_begin_list(t_completion *this, t_lst *all)
{
	char		*first;
	char		*ret;

	first = twl_strdup(twl_lst_first(all));
	twl_lst_iter(all, iter_fn, first);
	if (!*first || this->current_len == twl_strlen(first))
	{
		free(first);
		return (NULL);
	}
	ret = twl_strdup(first + this->current_len);
	free(first);
	return (ret);
}
