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

#include "ast/nodes/ast_separator.h"

t_ast_separator	*ast_separator_new_from_tokens(t_lst *tokens)
{
	t_ast_separator		*ast_separator;

	ast_separator = ast_separator_new();
	// twl_printf("ast_newline_list_is_own_type(tokens) %d\n", ast_newline_list_is_own_type(tokens));
	// twl_printf("ast_separator_op_is_own_type(tokens) %d\n", ast_separator_op_is_own_type(tokens));
	// token_mgr_print(tokens);
	ast_separator->ast_newline_list = ast_newline_list_new_from_tokens(tokens);
	if (ast_separator->ast_newline_list)
	{
		ast_separator->type = AST_SEPERATOR_NEWLINE_LIST;
		return ast_separator;
	}
	ast_separator->ast_separator_op = ast_separator_op_new_from_tokens(tokens);
	ast_separator->ast_linebreak = ast_linebreak_new_from_tokens(tokens);
	if (ast_separator->ast_separator_op && ast_separator->ast_linebreak)
	{
		ast_separator->type = AST_SEPERATOR_SEPARATOR_OP;
		return ast_separator;
	}
	return (NULL);
	(void)tokens;
}
