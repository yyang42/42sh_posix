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

#include "alias.h"

static void		iter_fn(void *elem, void *context)
{
	char	*str;
	char	*tmp;

	str = elem;
	if (twl_strchr(str, '='))
		set_alias(str);
	else
	{
		tmp = get_alias(str);
		if (tmp)
			twl_printf("%s=\'%s\'\n", str, tmp);
	}
	(void)context;
}

void			alias(char *str)
{
	char **tab;

	tab = twl_strsplit(str, ' ');
	if (twl_arr_len(tab) == 1)
		print_alias();
	else if (twl_arr_len(tab) > 1)
		twl_arr_iter(&tab[1], iter_fn, NULL);
	twl_arr_del(tab, free);
}
