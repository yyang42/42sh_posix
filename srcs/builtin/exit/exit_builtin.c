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

#include "twl_stdlib.h"

#include "builtin/exit.h"

int					exit_builtin(char *str, t_environment *this)
{
	char			*arg_str;
	int				exit_code;

	arg_str = str + ((int)twl_strlen("exit") + 1);
	if (twl_strlen(arg_str) == 0)
	{
		exit_code = 0;
	}
	else if (twl_str_is_num(arg_str))
	{
		exit_code = twl_atoi(arg_str);
	}
	else
	{
		twl_dprintf(2, "exit: %s: numeric argument required\n", arg_str);
		exit_code = 255;
	}
	exit(exit_code);
	return (0);
	(void)this;
}
