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

#include "ast/nodes/ast_function_def.h"
#include "ast/nodes/ast_compound_command.h"
#include "ast/ast.h"

t_ast_function_def	*ast_function_def_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_function_def		*this;
	t_token					*name_token;

	this = ast_function_def_new();
	name_token = twl_lst_pop_front(tokens);
	this->name = twl_strdup(name_token->text);
	twl_lst_pop_front(tokens);
	twl_lst_pop_front(tokens);
	this->compound_command = ast_compound_command_new_from_tokens(tokens, ast);
	// token_mgr_print(tokens);
	(void)tokens;
	(void)ast;
	return (this);
}
