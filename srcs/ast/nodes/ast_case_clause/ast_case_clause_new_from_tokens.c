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

t_ast_case_clause		*ast_case_clause_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_case_clause		*this;
	t_token				*open;

	this = ast_case_clause_new();
	open = twl_lst_pop_front(tokens);
	this->needle_token = twl_lst_pop_front(tokens); // TODO: handle missing needle
	twl_lst_pop_front(tokens); // TODO: handle missing 'in'
	while (true)
	{
		token_mgr_pop_linebreak(tokens);
		if (token_mgr_first_equ(tokens, "esac"))
			break ;
		twl_lst_push(this->case_list, ast_case_item_new_from_tokens(tokens, ast));

		if (token_mgr_first_equ(tokens, ";;"))
		{
			twl_lst_pop_front(tokens);
			continue;
		}
		else
		{
			break;
		}
	}
	// token_mgr_print(tokens);
	twl_lst_pop_front(tokens); // TODO: handle missing esac
	return (this);
	(void)open;
}
