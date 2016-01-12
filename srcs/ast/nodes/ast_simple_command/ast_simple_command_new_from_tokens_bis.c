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
#include "data.h"
#include "ast/ast.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

static bool			is_separator(char *str)
{
	return (twl_lst_find(data_all_separators(), twl_strequ_void, str));
}

t_ast_simple_command	*ast_simple_command_new_from_tokens_bis(t_lst *tokens, struct s_ast *ast)
{
	t_ast_simple_command		*this;

	this = ast_simple_command_new();
	this->command_tokens = twl_lst_new();
	while (token_mgr_first(tokens)
		&& !is_separator(token_mgr_first(tokens)->text)
		)
	{
		twl_lst_push(this->command_tokens, twl_lst_pop_front(tokens));
	}

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
