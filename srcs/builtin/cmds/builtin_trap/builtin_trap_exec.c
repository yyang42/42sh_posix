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

static bool			is_unset_following_conditions(
		char *first_token, t_lst *remainders)
{
	if (twl_lst_len(remainders) >= 2 && twl_strequ(first_token, "-"))
	{
		twl_lst_pop_front(remainders);
		return (true);
	}
	else if (twl_str_is_pos_num(first_token))
	{
		return (true);
	}
	return (false);
}

static bool			is_invalid_should_print_usage(t_lst *remainders)
{
	if (twl_lst_len(remainders) == 1
		&& twl_strequ(twl_lst_first(remainders), "-"))
		return (true);
	return (false);
}

void				builtin_trap_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;
	t_lst				*remainders;

	argparser_result = argparser_parse_tokens(builtin_trap_argparser(), tokens);
	env->shenv_cur_token = token_mgr_first(tokens);
	remainders = twl_lst_copy(argparser_result->remainders, NULL);
	if (argparser_result->err_msg ||
			is_invalid_should_print_usage(argparser_result->remainders))
		argparser_result_print_usage_exit_status(argparser_result, 2);
	else
	{
		if (twl_lst_len(remainders) == 0)
			builtin_trap_print(env);
		else if (is_unset_following_conditions(
					twl_lst_first(remainders), remainders))
			builtin_trap_exec_unset(remainders);
		else if (twl_lst_len(remainders) >= 2)
			builtin_trap_exec_set(remainders);
		else
			LOG_ERROR("Should run");
	}
	twl_lst_del(remainders, NULL);
	argparser_result_del(argparser_result);
}
