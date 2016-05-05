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
#include "twl_unistd.h"

static void			init_getopts(t_shenv *env)
{
	char			*optind_str;

	shenv_unsetenv(env, "OPTARG");

	optind_str = shenv_shvars_get_value(env, "OPTIND");
	g_twl_optind = optind_str ? twl_atoi(optind_str) : 1;
}

static void			process(char *optstring, char *varname, char **argv, t_shenv *env)
{
	char			getopt_c;

	LOG_DEBUG("optstring   %s", optstring);
	LOG_DEBUG("varname     %s", varname);
	LOG_DEBUG("pos_params  %s", twl_strjoinarr((const char **)argv, " "));
	init_getopts(env);
	getopt_c = twl_getopt(twl_arr_len(argv), argv, optstring);
	shenv_shvars_set_int(env, "OPTIND", g_twl_optind, "getopts");
	if (getopt_c == -1)
	{
		env->last_exit_code = EXIT_FAILURE;
		return ;
	}
	LOG_DEBUG("g_twl_optopt  {%c}", g_twl_optopt);
	shenv_shvars_set(env, varname, (char[2]){g_twl_optopt, '\0'}, "getopts");
	LOG_DEBUG("getopt_c %c", getopt_c);
	if (g_twl_optarg)
	{
		shenv_shvars_set(env, "OPTARG", g_twl_optarg, "getopts");
		LOG_DEBUG("g_twl_optarg %s", g_twl_optarg);
	}
}

void				builtin_getopts_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;
	char				*optstring;
	char				*varname;
	char				**argv;
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
		twl_lst_del(remainders_copy, NULL);

		remainders_copy = twl_lst_copy(env->pos_params, NULL);
		twl_lst_push_front(remainders_copy, "getopts");
		argv = (char **)twl_lst_to_arr(remainders_copy);
		process(optstring, varname, argv, env);
		twl_arr_del(argv, NULL);
		twl_lst_del(remainders_copy, NULL);
	}
}
