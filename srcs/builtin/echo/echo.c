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

#include "builtin/echo.h"

int				builtin_echo(t_lst *tokens, t_environment *this)
{
	t_opt			*opt;
	char			**arr;
	int				flag;
	char			*str;

	flag = 0;
	(void)this;
	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, ECHO_OPT_VALID_OPTS);
	if (twl_opt_exist(opt, "n"))
		twl_printf(str + 8);
	else
		twl_printf("%s\n", str + 5);
	environment_set_last_exit_status_2(this, BUILTIN_EXEC_SUCCESS);
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	return (flag);
}
