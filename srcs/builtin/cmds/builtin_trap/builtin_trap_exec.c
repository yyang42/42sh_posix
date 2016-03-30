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

#include "builtin/cmds/builtin_trap.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"

static void			iter_trap_fn(void *sigstr, void *action)
{
	t_shsignal		*shsignal;

	shsignal = shsignal_mgr_find_by_signame(data_signals_with_exit(), sigstr);
	if (!shsignal && twl_str_is_pos_num(sigstr))
	{
		shsignal = shsignal_mgr_find_by_signum(data_signals_with_exit(), twl_atoi(sigstr));
	}
	if (shsignal)
	{
		trap_mgr_add(shenv_singleton()->traps, action, shsignal->signum);
	}
	else
	{
		builtin_trap_print_invalid_sig_error(sigstr);
	}
}

static void			builtin_trap_exec_trap(t_lst *args)
{
	t_lst			*args_copy;
	char			*action;

	args_copy = twl_lst_copy(args, NULL);
	action = twl_lst_pop_front(args_copy);
	twl_lst_iter(args_copy, iter_trap_fn, action);
	twl_lst_del(args_copy, NULL);
}

static bool			is_unset(t_lst *tokens)
{
	return ((twl_lst_len(tokens) >= 2)
		&& twl_strequ(token_mgr_get(tokens, 1)->text, "-"));
}

void				builtin_trap_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(builtin_trap_argparser(), tokens);
	env->shenv_cur_token = token_mgr_first(tokens);
	env->last_exit_code = EXIT_SUCCESS;
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
		env->last_exit_code = 2;
	}
	else
	{
		if (is_unset(tokens))
		{
			builtin_trap_exec_unset(argparser_result->remainders);
		}
		else if (twl_lst_len(argparser_result->remainders) >= 2)
		{
			builtin_trap_exec_trap(argparser_result->remainders);
		}
		else
		{
			builtin_trap_print(env);
		}
	}
}
