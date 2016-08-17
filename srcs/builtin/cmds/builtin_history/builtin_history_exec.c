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

#include "builtin/cmds/builtin_history.h"

static void			inner_history_fn(t_argparser_result *result)
{
	if (argparser_result_opt_is_set(result, "c"))
		builtin_history_clear();
	if (argparser_result_opt_is_set(result, "d"))
		builtin_history_del_offset(result);
	if (argparser_result_opt_is_set(result, "a"))
		builtin_history_append_file(result);
	else if (argparser_result_opt_is_set(result, "n"))
		builtin_history_append_list(result);
	else if (argparser_result_opt_is_set(result, "r"))
		builtin_history_append_all_file(result);
	else if (argparser_result_opt_is_set(result, "w"))
		builtin_history_append_all_list(result);
	else if (argparser_result_opt_is_set(result, "s"))
		builtin_history_append_args_to_list(result);
	else if (argparser_result_opt_is_set(result, "p"))
		builtin_history_perform_substitution(result);
}

void				builtin_history_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*result;

	result = argparser_parse_tokens(builtin_history_argparser(), tokens);
	if (result->err_msg)
	{
		argparser_result_print_error_with_help(result);
		env->last_exit_code = EXIT_FAILURE;
	}
	else if (twl_lst_first(result->result_items))
	{
		inner_history_fn(result);
	}
	else
	{
		builtin_history_dump();
	}
	argparser_result_del(result);
}
