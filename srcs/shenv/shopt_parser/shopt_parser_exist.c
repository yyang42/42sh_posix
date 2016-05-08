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

#include "shenv/shopt_parser.h"
#include "twl_opt_elem.h"

static bool			find_opt(void *opt_elem_, void *opt_key)
{
	t_opt_elem *opt_elem;

	opt_elem = opt_elem_;
	if (twl_strcmp(opt_elem->key, opt_key) == 0)
		return (true);
	return (false);
}

int					shopt_parser_exist(t_set_opt *twl_opt, char *opt_key)
{
	if (twl_lst_find(twl_opt->positive_opts, find_opt, opt_key))
		return (POSITIVE_OPT);
	else if (twl_lst_find(twl_opt->negative_opts, find_opt, opt_key))
		return (NEGATIVE_OPT);
	return (0);
}
