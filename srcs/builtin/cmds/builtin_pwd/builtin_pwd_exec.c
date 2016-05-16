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

#include "builtin/cmds/builtin_pwd.h"

void			builtin_pwd_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result	*result;

	result = argparser_parse_tokens(builtin_pwd_argparser(), tokens);
	if (result->err_msg)
	{
		shenv_singl_error(1, result->err_msg);
		argparser_print_help(builtin_pwd_argparser());
		return ;
	}
	twl_printf("%s\n", shenv->shenv_current_directory);
	//if (argparser_result_opt_is_set(result, "P"))
	//{
	//	builtin_pwd_exec_physical();
	//}
	//else
	//{
	//	builtin_pwd_exec_logical();
	//}
	//argparser_result_del(result);
	(void)shenv;
}
