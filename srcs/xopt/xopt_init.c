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

#include "xopt.h"
#include "twl_dict.h"

static void			fill_flag_verbose_dict(t_dict *dict)
{
	twl_dict_add(dict, "a", "allexport");
	twl_dict_add(dict, "e", "errexit");
	twl_dict_add(dict, "C", "noclobber");
	twl_dict_add(dict, "f", "noglob");
	twl_dict_add(dict, "b", "notify");
	twl_dict_add(dict, "ignoreeof", "ignoreeof");
	twl_dict_add(dict, "m", "monitor");
	twl_dict_add(dict, "n", "noexec");
	twl_dict_add(dict, "u", "nounset");
	twl_dict_add(dict, "v", "verbose");
	twl_dict_add(dict, "vi", "vi");
}

void				xopt_init(t_xopt *xopt, char **av)
{
	xopt->opt__ = twl_opt_new(av, XOPT_VALID_OPTS);
	xopt->flag_verbose = twl_dict_new();
	fill_flag_verbose_dict(xopt->flag_verbose);
	xopt_check_valid_opts(xopt);
}
