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

#include "echo.h"

int				echo(char *str)
{
	t_opt			*opt;
	char			**arr;
	char			*c;
	int				flag;

	flag = 0;
	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, ECHO_OPT_VALID_OPTS);
	if ((c = twl_opt_check_invalid_opts(opt)))
		flag = check_invalid_opts(opt, "echo", ECHO_OPT_VALID_OPTS);
	else
	{
		if (twl_opt_get_param(opt, "n"))
			twl_printf("%s", str);
		else
			twl_printf("%s\n", str);
	}
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	return (flag);
}
