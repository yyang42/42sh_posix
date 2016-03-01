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

#include <stdbool.h>
#include "builtin/builtin_set.h"
#include "twl_opt.h"
#include "twl_opt_elem.h"
#include "twl_stdio.h"

static bool			find_fn(void *opt_elem_, void *valid_opts_)
{
	t_opt_elem		*opt_elem;
	char			*valid_opts;

	opt_elem = opt_elem_;
	valid_opts = valid_opts_;
	if (!twl_strchr(valid_opts, *opt_elem->key))
		return (true);
	return (false);
}

char				*set_opt_check_invalid_opts(t_set_opt *opt)
{
	t_opt_elem		*opt_elem;

	opt_elem = twl_lst_find(opt->positive_opts, find_fn, opt->valid_opts);
	if (opt_elem)
	{
		return (opt_elem->key);
	}
	opt_elem = twl_lst_find(opt->negative_opts, find_fn, opt->valid_opts);
	if (opt_elem)
	{
		return (opt_elem->key);
	}
	return (NULL);
}
