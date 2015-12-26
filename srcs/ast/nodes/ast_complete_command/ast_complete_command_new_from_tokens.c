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
	t_ast_complete_command		*ast_complete_command;
	t_token						*token;

	ast_complete_command = ast_complete_command_new();
	while (true)
	{
		twl_lst_push(ast_complete_command->ast_and_or_seq_lst, ast_and_or_seq_new_from_tokens(tokens));
		token = token_mgr_first(tokens);
		if (!token)
			break ;
		if (ast_and_or_seq_is_delimiter(token))
			twl_lst_shift(tokens);
		else
			break ;
	}
	return (ast_complete_command);
}
