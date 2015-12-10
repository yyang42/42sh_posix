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

#include "twl_xstdlib.h"

#include "ast.h"

#include "anode_compound_stmt.h"
#include "anode_if_stmt.h"
#include "anode.h"

static void			ast_build(t_ast *ast)
{
	t_anode_compound_stmt	*anode_compound_stmt;

	anode_compound_stmt = anode_compound_stmt_new();
	twl_lst_push(ast->root->items, anode_if_stmt_new());
	twl_lst_push(ast->root->items, anode_if_stmt_new());
	twl_lst_push(ast->root->items, anode_compound_stmt);
	twl_lst_push(anode_compound_stmt->items, anode_if_stmt_new());
	twl_lst_push(anode_compound_stmt->items, anode_if_stmt_new());
	twl_lst_push(anode_compound_stmt->items, anode_if_stmt_new());
	(void)ast;
}

t_ast				*ast_new(char *input)
{
	t_ast			*this;

	this = twl_malloc_x0(sizeof(t_ast));
	this->raw = twl_strdup(input);
	this->root = anode_compound_stmt_new();
	ast_build(this);
	return (this);
}
