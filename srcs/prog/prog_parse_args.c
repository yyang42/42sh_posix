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

#include "prog.h"
#include "twl_unistd.h"
#include "twl_arr.h"

#define VALID_OPTS ":c:eA"

static void			process_arg(t_prog *prog, char sign, char c, char *optarg)
{
	t_shenv			*env;

	env = shenv_singleton();
	LOG_DEBUG("found:     %c%c", sign, c);
	if (optarg && c != '?')
	{
		LOG_DEBUG("           %s", optarg);
	}
	if (c == 'A')
		env->shenv_flags |= SHENV_FLAG_AST;
	else if (c == 'E')
		env->shenv_flags |= SHENV_FLAG_AREXP;
	else if (c == 'G')
		env->shenv_flags |= SHENV_FLAG_GNL;
	else if (c == 'c' && optarg)
		prog->prog_command_arg = twl_strdup(optarg);
}

static void			print_help(char invalid_opt)
{
	twl_dprintf(2, "%s: -%c: invalid option\n", shenv_singleton()->shenv_name, invalid_opt);
	twl_dprintf(2, "Usage:	%s [option] [script-file]\n", shenv_singleton()->shenv_name);
	twl_dprintf(2, "Shell options\n");
	twl_dprintf(2, "\t-c command\n");
	// twl_dprintf(2, "\t-abefhkmnptuvxBCHP or -o option\n");
	exit(2);
}

void				prog_parse_args(t_prog *prog, char **argv)
{
	char			getopt_c;

	g_twl_optsign_active = true;
	while ((getopt_c = twl_getopt(twl_arr_len(argv), argv, VALID_OPTS)) > 0)
	{
		if (getopt_c == '?')
		{
			print_help(g_twl_optopt);
			LOG_DEBUG("not found: %c%c", g_twl_optsign, g_twl_optopt);
			exit(1);
		}
		else
		{
			process_arg(prog, g_twl_optsign, getopt_c, g_twl_optarg);
		}
	}
	if (g_twl_optind < (int)twl_arr_len(argv))
		shenv_singleton()->shenv_argv_remainder = twl_arr_to_lst(argv + g_twl_optind);
	else
		shenv_singleton()->shenv_argv_remainder = twl_lst_new();
	g_twl_optind = 0;
	g_twl_optsign_active = false;
}
