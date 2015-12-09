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

#include "set.h"
#include "twl_opt.h"
#include "twl_opt_elem.h"
#include "twl_xstring.h"

static void	remove_shell_flags(void *data)
{
	t_opt_elem *elem;

	elem = data;
	twl_printf("%s", (char*)(elem->key));
	twl_printf("%s", (char*)(elem->value));
}

static void	add_shell_flags(void *data)
{
	t_opt_elem *elem;

	elem = data;
	twl_printf("%s", (char*)(elem->key));
	twl_printf("%s", (char*)(elem->value));
	if (twl_strcmp(elem->key, "o") != 0)
		set_add_flag(elem->key);
}

void	set(char *str)
{
	t_set_opt		*opt;
	char			**arr;

	arr = twl_strsplit_mul(str, " \n\t");
	opt = set_opt_new(arr, SET_OPT_VALID_OPTS);
	twl_lst_iter0(opt->negative_opts, remove_shell_flags);
	twl_lst_iter0(opt->positive_opts, add_shell_flags);
	set_opt_del(opt);
}
