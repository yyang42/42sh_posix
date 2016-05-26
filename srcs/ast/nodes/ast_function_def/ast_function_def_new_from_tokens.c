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
	token_mgr_pop_linebreak(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		ast_add_to_open_stack(ast, this->name);
		ast_set_error_msg_syntax_error_near(ast, name_token, "Missing compound command");
		ast_function_def_del(this);
		return (NULL);
	}
	this->compound_command = ast_compound_command_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_function_def_del(this);
		return (NULL);
	}
	return (this);
}
