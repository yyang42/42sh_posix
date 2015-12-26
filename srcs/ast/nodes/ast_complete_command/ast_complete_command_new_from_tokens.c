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

#include "ast/nodes/ast_complete_command.h"

t_ast_complete_command	*ast_complete_command_new_from_tokens(t_lst *tokens)
{
	t_ast_complete_command		*complete_command;

	complete_command = ast_complete_command_new();
	// twl_printf("tokens %zu\n", twl_lst_len(tokens));
	// token_mgr_print(tokens);
	complete_command->list = ast_list_new_from_tokens(tokens);
	// twl_printf("tokens %zu\n", twl_lst_len(tokens));
	// token_mgr_print(tokens);
	if (twl_lst_len(tokens) > 0)
		complete_command->separator = ast_separator_new_from_tokens(tokens);
	// twl_printf("tokens %zu\n", twl_lst_len(tokens));
	return (complete_command);
}
