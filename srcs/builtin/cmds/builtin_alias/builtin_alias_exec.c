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

#include "builtin/cmds/builtin_alias.h"

static void		iter_fn(void *elem, void *context)
{
	char			*str;
	char			*tmp;
	t_shenv	*this;

	str = elem;
	this = context;
	if (twl_strchr(str, '='))
		builtin_alias_set(str, this);
	else
	{
		tmp = builtin_alias_get(str, this);
		if (tmp)
			twl_printf("%s=\'%s\'\n", str, tmp);
	}
}

void				builtin_alias_exec(t_lst *tokens, t_shenv *this)
{
	char			**tab;

	tab = token_mgr_to_str_arr(tokens);
	if (twl_arr_len(tab) == 1)
		builtin_alias_print(this);
	else if (twl_arr_len(tab) > 1)
		twl_arr_iter(&tab[1], iter_fn, this);
	twl_arr_del(tab, NULL);
}
