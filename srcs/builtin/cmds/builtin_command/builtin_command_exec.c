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

#include "builtin/cmds/builtin_command.h"

void					builtin_command_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result	*result;

	result = argparser_parse_tokens(builtin_command_argparser(), tokens);
	if (result->err_msg)
	{
		argparser_result_print_error_with_help(result);
		shenv->last_exit_code = EXIT_FAILURE;
	}
	argparser_result_del(result);
}
