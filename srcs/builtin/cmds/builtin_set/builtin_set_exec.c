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

#include "builtin/cmds/builtin_set.h"
#include "twl_unistd.h"
#include "twl_arr.h"

static void			process_arg(char sign, char c, char *optarg)
{
	shflag_utils_process_shopts(sign, c, optarg);
}

static void			print_help(char sign, char invalid_opt)
{
	shenv_singl_error(2, "set: %c%c: invalid option", sign, invalid_opt);
	twl_dprintf(2, "set: usage: set [--%s] [-o option] [arg ...]\n", FTSH_VALID_SET_OPTS);
}

static void			process_opt_o(char sign)
{
	if (sign == '-')
		shflag_mgr_print_on_off(shenv_singleton()->shenv_shflags);
	else if (sign == '+')
		shflag_mgr_print_set_plus_o(shenv_singleton()->shenv_shflags);
	else
		LOG_ERROR("bad sign: %c", sign);

}

static void			copy_pos_params(char **arr)
{
	while (*arr)
	{
		twl_lst_push_back(shenv_singleton()->shenv_pos_params, twl_strdup(*arr));
		arr++;
	}
}

static void			prog_parse_args(char **argv)
{
	char			getopt_c;

	g_twl_optsign_active = true;
	while ((getopt_c = twl_getopt(twl_arr_len(argv), argv, FTSH_VALID_ALL_OPTS)) > 0)
	{
		if (getopt_c == ':')
		{
			if (g_twl_optopt == 'o')
				process_opt_o(g_twl_optsign);
			else
				LOG_ERROR("opt arg required: %c", g_twl_optopt);
		}
		else if (getopt_c == '?')
		{
			print_help(g_twl_optsign, g_twl_optopt);
			exit(2);
		}
		else
		{
			process_arg(g_twl_optsign, getopt_c, g_twl_optarg);
		}
	}
	if (g_twl_optind < (int)twl_arr_len(argv))
	{
		shenv_remove_all_pos_params(shenv_singleton());
		copy_pos_params(argv + g_twl_optind);
	}
	g_twl_optind = 0;
	g_twl_optsign_active = false;
}

static void			builtin_set_exec_args(t_lst *tokens_copy)
{
	char			**arr;

	arr = token_mgr_to_str_arr(tokens_copy);
	prog_parse_args(arr);
	twl_arr_del(arr, NULL);
}

void				builtin_set_exec(t_lst *tokens, t_shenv *env)
{
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	if (twl_lst_len(tokens_copy) == 0)
	{
		builtin_set_exec_print(env);
	}
	else
	{
		if (twl_strequ(token_mgr_get(tokens_copy, 0)->text, "--"))
		{
			shenv_remove_all_pos_params(env);
			if (twl_lst_len(tokens_copy) == 1)
			{
				twl_lst_del(tokens_copy, NULL);
				return ;
			}
		}
	}
	builtin_set_exec_args(tokens);
	twl_lst_del(tokens_copy, NULL);
}
