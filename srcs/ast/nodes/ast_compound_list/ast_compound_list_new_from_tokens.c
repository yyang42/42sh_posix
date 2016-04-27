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
#include "ast/ast_lap.h"

t_ast_compound_list	*ast_compound_list_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_compound_list			*this;

	this = ast_compound_list_new();
	twl_lst_del(this->ast_list_items, NULL); // LEAKS it's reallocate juste above
	token_mgr_pop_linebreak(tokens);

	this->ast_list_items = ast_lap_build_items(tokens, AST_TYPE_LIST_ITEM, ast);
	if (ast_has_error(ast))
		return (NULL);
	return this;
}
