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

#include "ast/nodes/ast_command.h"
#include "ast/nodes/ast_pipe_item.h"
#include "ast/nodes/ast_andor_item.h"
#include "ast/nodes/ast_list_item.h"

t_ast_command	*ast_command_new_from_tokens(t_lst *tokens)
{
	t_ast_command		*ast_command;
	t_token				*token;

	ast_command = ast_command_new();
	while (true)
	{
		token = token_mgr_first(tokens);
		if (!token)
			break ;
		if (ast_pipe_item_is_delimiter(token)
			|| ast_andor_item_is_delimiter(token)
			|| ast_list_item_is_delimiter(token))
			break ;
		twl_lst_push(ast_command->tokens, twl_lst_shift(tokens));
	}
	return (ast_command);
	(void)tokens;
}
