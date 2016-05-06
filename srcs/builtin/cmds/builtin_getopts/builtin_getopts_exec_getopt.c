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
	if (!optind_str)
	{
		optind_str = "1";
		LOG_ERROR("OPTIND is not initialized");
	}
	g_twl_optind = optind_str ? twl_atoi(optind_str) : 1;
}

static char			*builtin_getopt_string(char *original_optstring)
{
	char			*optstring_with_colon;

	if (*original_optstring == ':')
		optstring_with_colon = twl_strdup(original_optstring);
	else
		optstring_with_colon = twl_strjoin(":", original_optstring);
	return (optstring_with_colon);
}

static void			set_optind(char **argv, t_shenv *env)
{
	int				ind;

	ind = g_twl_optind;
	if (ind > (int)twl_arr_len(argv))
		ind = twl_arr_len(argv);
	shenv_shvars_set_int(env, "OPTIND", ind, "getopts");
}

void				builtin_getopts_exec_getopt(char *original_optstring,
					char *varname, char **argv, t_shenv *env)
{
	char			getopt_c;
	char			opt_value[2];
	char			*optstring_with_colon;

	twl_bzero(opt_value, 2);
	optstring_with_colon = builtin_getopt_string(original_optstring);
	LOG_DEBUG("optstring   {%s}", optstring_with_colon);
	LOG_DEBUG("varname     {%s}", varname);
	LOG_DEBUG("pos_params  {%s}", twl_strjoinarr((const char **)argv, " "));
	init_getopts(env);
	g_twl_optopt = '@';
	LOG_DEBUG("g_twl_optopt  {%c} 1", g_twl_optopt);
	getopt_c = twl_getopt(twl_arr_len(argv), argv, optstring_with_colon);
	LOG_DEBUG("g_twl_optopt  {%c} 2", g_twl_optopt);
	set_optind(argv, env);
	if (getopt_c == -1)
	{
		env->last_exit_code = EXIT_FAILURE;
		return ;
	}
	*opt_value = getopt_c;
	LOG_DEBUG("getopt_c %c", getopt_c);
	if (getopt_c == ':')
	{
		*opt_value = '?';
		twl_dprintf(2, "%s: option requires an argument -- %c\n", shenv_singleton()->shenv_name, g_twl_optopt);
	}
	else if (getopt_c == '?')
	{
		twl_dprintf(2, "%s: illegal option -- %c\n", shenv_singleton()->shenv_name, g_twl_optopt);
	}
	LOG_DEBUG("g_twl_optopt  {%c} 3", g_twl_optopt);
	shenv_shvars_set(env, varname, opt_value, "getopts");
	if (g_twl_optarg)
	{
		shenv_shvars_set(env, "OPTARG", g_twl_optarg, "getopts");
		LOG_DEBUG("g_twl_optarg %s", g_twl_optarg);
	}
}
