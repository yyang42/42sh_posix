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

#include "data.h"
#include "ast/ast.h"
#include "token/token_list_mgr.h"
#include "token/token_utils.h"
#include "ast/nodes/ast_case_clause.h"
#include "ast/nodes/ast_case_item.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

static void			handle_cases(t_ast_case_clause *this,
	t_lst *tokens, struct s_ast *ast)
{
	while (true)
	{
		token_mgr_pop_linebreak(tokens);
		if (token_mgr_first_equ(tokens, "esac") || twl_lst_len(tokens) == 0)
			break ;
		t_ast_case_item *case_item;
		case_item = ast_case_item_new_from_tokens(tokens, ast);
		if (ast_has_error(ast))
			return ;
		twl_lst_push_back(this->case_list, case_item);
		if (token_mgr_first_equ(tokens, ";;"))
		{
			twl_lst_pop_front(tokens);
			continue ;
		}
		else
		{
			break ;
		}
	}
}

t_ast_case_clause		*ast_case_clause_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_case_clause	*this;
	t_token				*open;

	open = twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		ast_add_to_open_stack(ast, "case");
		ast_set_error_msg_syntax_error_near(ast, open, NULL);
		return (NULL);
	}
	this = ast_case_clause_new();
	this->needle_token = token_copy(twl_lst_pop_front(tokens));
	if (!token_mgr_first_equ(tokens, "in"))
	{
		ast_add_to_open_stack(ast, "case");
		ast_set_error_msg_syntax_error_missing(ast, open, "in");
		ast_case_clause_del(this);
		return (NULL);
	}
	twl_lst_pop_front(tokens);
	handle_cases(this, tokens, ast);
	if (ast_has_error(ast))
	{
		ast_case_clause_del(this);
		return (NULL);
	}
	if (!token_mgr_first_equ(tokens, "esac"))
	{
		ast_add_to_open_stack(ast, "case");
		ast_set_error_msg_syntax_error_missing(ast, open, "esac");
		ast_case_clause_del(this);
		return (NULL);
	}
	twl_lst_pop_front(tokens);
	return (this);
}
