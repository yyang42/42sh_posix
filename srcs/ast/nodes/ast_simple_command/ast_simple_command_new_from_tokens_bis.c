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

#include "token/token_list_mgr.h"
#include "ast/ast.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

t_ast_simple_command	*ast_simple_command_new_from_tokens_bis(t_lst *tokens, struct s_ast *ast)
{
	t_ast_simple_command		*this;

	this = ast_simple_command_new();
	this->command_tokens = twl_lst_copy(tokens, NULL);
	// build_tokens(this, tokens, ast);
	// if (ast_has_error(ast))
	// {
	// 	ast_simple_command_del(this);
	// 	return (NULL);
	// }
	return (this);
	(void)ast;
	(void)tokens;
}
