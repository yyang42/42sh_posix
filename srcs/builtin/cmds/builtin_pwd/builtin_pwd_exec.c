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
#include "builtin/cmds/builtin_cd.h"

void			builtin_pwd_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result	*result;
	char				*path;

	result = argparser_parse_tokens(builtin_pwd_argparser(), tokens);
	if (result->err_msg)
	{
		shenv_singl_error(1, result->err_msg);
		argparser_print_help(builtin_pwd_argparser());
		return ;
	}
	path = shenv_get_current_directory(shenv_singleton(), "pwd");
	if (!path)
		;
	else if (argparser_result_opt_is_set(result, "P"))
	{
		if ((path = builtin_cd_phypath(path)))
		{
			twl_printf("%s\n", path);
			free(path);
		}
	}
	else
		twl_printf("%s\n", path);
	argparser_result_del(result);
	(void)shenv;
}
