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
#include "ast/nodes/ast_list_item.h"

t_ast_pipe_item	*ast_pipe_item_new_from_tokens(t_lst *tokens, t_token *separator)
{
	t_ast_pipe_item		*ast_pipe_item;

	ast_pipe_item = ast_pipe_item_new();
	ast_pipe_item->tokens = twl_lst_copy(tokens, NULL);
	ast_pipe_item->separator = separator;
	ast_pipe_item->ast_command = ast_command_new_from_tokens(tokens);
	if (ast_pipe_item->ast_command == NULL)
		return (NULL);
	return (ast_pipe_item);
}
