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
#include "token/token_mgr.h"
#include "ast/nodes/ast_list_item.h"
#include "ast/ast.h"
#include "data.h"

t_ast_list_item		*ast_list_item_new_from_tokens_bis(t_lst *tokens, struct s_ast *ast)
{
	t_ast_list_item				*this;

	this = ast_list_item_new();


	t_ast_andor_item			*ast_andor_item;
	ast_andor_item = ast_andor_item_new_from_tokens_bis(tokens, ast);
	twl_lst_push(this->ast_andor_items, ast_andor_item);
	(void)ast;
	(void)tokens;
	return (this);
}
