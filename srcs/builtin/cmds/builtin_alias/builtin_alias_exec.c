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

#include "builtin/cmds/builtin_alias.h"

static void		iter_alias_fn(void *str_, void *env)
{
	char			*tmp;
	char			*str;

	str = str_;
	if (twl_strchr(str, '=') && (*str != '='))
	{
		builtin_alias_set(str, env);
	}
	else
	{
		tmp = builtin_alias_get(str, env);
		if (tmp)
			twl_printf("%s=\'%s\'\n", str, tmp);
		else
			shenv_singl_error(EXIT_FAILURE, "alias: %s: not found", str);
	}
}

void			builtin_alias_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(
			builtin_alias_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
		env->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		if (twl_lst_len(argparser_result->remainders) == 0)
			builtin_alias_print(env);
		else
			twl_lst_iter(argparser_result->remainders, iter_alias_fn, env);
	}
	argparser_result_del(argparser_result);
}
