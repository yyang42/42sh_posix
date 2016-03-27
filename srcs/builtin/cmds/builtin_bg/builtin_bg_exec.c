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

#include "builtin/cmds/builtin_bg.h"

void				builtin_bg_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result *argparser_result;

	argparser_result = argparser_parse_tokens(builtin_bg_argparser(), tokens);
	shenv->last_exit_code = EXIT_SUCCESS;
	shenv->shenv_cur_token = token_mgr_first(tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
		// shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		builtin_bg_exec_segs(argparser_result);
	}
}
