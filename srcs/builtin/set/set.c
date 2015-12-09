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

void	builtin_set(char *str)
{
	t_opt			*opt;
	char			**arr;

	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, SET_OPT_VALID_OPTS);
	twl_printf("%s", twl_opt_get_param(opt, "o"));
	twl_opt_del(opt);
}
