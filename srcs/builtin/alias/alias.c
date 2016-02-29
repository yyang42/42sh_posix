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

#include "builtin/alias.h"

static void		iter_fn(void *elem, void *context)
{
	char			*str;
	char			*tmp;
	t_environment	*this;

	str = elem;
	this = context;
	if (twl_strchr(str, '='))
		set_alias(str, this);
	else
	{
		tmp = get_alias(str, this);
		if (tmp)
			twl_printf("%s=\'%s\'\n", str, tmp);
	}
}

void				builtin_alias(t_lst *tokens, t_environment *this)
{
	char **tab;
	char				*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	tab = twl_strsplit(str, ' ');
	if (twl_arr_len(tab) == 1)
		print_alias(this);
	else if (twl_arr_len(tab) > 1)
		twl_arr_iter(&tab[1], iter_fn, this);
	twl_arr_del(tab, free);
}
