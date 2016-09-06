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
#include "ast/nodes/ast_case_item.h"

static void		skip_first_optional_open_parenthesis(t_lst *tokens)
{
	if (token_mgr_first_equ(tokens, "("))
		twl_lst_pop_front(tokens);
}

static void		build_pattern_tokens(t_ast_case_item *this, t_lst *tokens)
{
	twl_lst_push_back(this->pattern_tokens,
			token_copy(twl_lst_pop_front(tokens)));
	while (true)
	{
		if (!token_mgr_first_equ(tokens, "|"))
			break ;
		twl_lst_pop_front(tokens);
		twl_lst_push_back(this->pattern_tokens,
				token_copy(twl_lst_pop_front(tokens)));
	}
}

t_ast_case_item	*ast_case_item_new_from_tokens_end(t_ast_case_item *this,
		t_lst *tokens, struct s_ast *ast)
{
	twl_lst_pop_front(tokens);
	this->compound_list = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_case_item_del(this);
		return (NULL);
	}
	return (this);
}

t_ast_case_item	*ast_case_item_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_case_item		*this;

	this = ast_case_item_new();
	skip_first_optional_open_parenthesis(tokens);
	if (token_mgr_first_equ(tokens, ")"))
	{
		ast_set_error_msg_syntax_error_unexpected(ast, token_mgr_first(tokens));
		ast_case_item_del(this);
		return (NULL);
	}
	build_pattern_tokens(this, tokens);
	if (!token_mgr_first_equ(tokens, ")"))
	{
		ast_set_error_msg_syntax_error_missing(ast,
				token_mgr_first(this->pattern_tokens), ")");
		ast_case_item_del(this);
		return (NULL);
	}
	return (ast_case_item_new_from_tokens_end(this, tokens, ast));
}
