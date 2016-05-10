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

#include "builtin/cmds/builtin_getopts.h"

static void			prep_exec_getopts(char *optstring,
					char *varname, t_lst *remainders, t_shenv *env)
{
	char			**argv;
	t_lst			*argv_lst;

	if (twl_lst_len(remainders))
		argv_lst = twl_lst_copy(remainders, NULL);
	else
		argv_lst = twl_lst_copy(env->shenv_pos_params, NULL);
	twl_lst_push_front(argv_lst, "getopts");
	argv = (char **)twl_lst_to_arr(argv_lst);
	builtin_getopts_exec_getopt(optstring, varname, argv, env);
	twl_arr_del(argv, NULL);
	twl_lst_del(argv_lst, NULL);
}

void				builtin_getopts_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;
	char				*optstring;
	char				*varname;
	t_lst				*remainders_copy;

	argparser_result = argparser_parse_tokens(builtin_getopts_argparser(), tokens);
	if (argparser_result->err_msg || twl_lst_len(argparser_result->remainders) < 2)
	{
		argparser_result_print_error_with_help(argparser_result);
		env->last_exit_code = 2;
	}
	else
	{
		remainders_copy = twl_lst_copy(argparser_result->remainders, NULL);
		optstring = twl_lst_pop_front(remainders_copy);
		varname = twl_lst_pop_front(remainders_copy);
		prep_exec_getopts(optstring, varname, remainders_copy, env);
		twl_lst_del(remainders_copy, NULL);
	}
}
