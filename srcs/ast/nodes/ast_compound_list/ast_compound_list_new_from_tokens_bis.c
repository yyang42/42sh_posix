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
#include "data.h"

#include "ast/nodes/ast_compound_list.h"

t_ast_compound_list	*ast_compound_list_new_from_tokens_bis(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_compound_list			*this;
	this = ast_compound_list_new();

	t_ast_list_item				*ast_list_item;
	ast_list_item = ast_list_item_new_from_tokens_bis(tokens, ast);
	twl_lst_push(this->ast_list_items, ast_list_item);
	return this;
	(void)ast;
}
