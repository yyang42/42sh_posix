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
#include "anode_string_literal.h"
#include "anode.h"

#include "twl_arr.h"
#include "twl_xstring.h"

static void			ast_build(t_ast *ast)
{
	char					**segs;

	segs = twl_strsplit_mul_trim_chars(ast->raw, AST_SEPARATOR_OP,
															AST_WHITE_SPACE);
	twl_arr_putstr(segs, "\n");
	twl_printf("\n======\n");
	while (*segs)
	{
		if (twl_str_starts_with(*segs, "if "))
		{
			t_anode_if_stmt 			*if_stmt = anode_if_stmt_new();
			twl_lst_push(ast->root->items, if_stmt);
			if_stmt->body = anode_compound_stmt_new();
			if_stmt->cond = anode_string_literal_new(*segs);
			segs++;
			while (!twl_str_starts_with(*segs, "fi"))
			{
				twl_lst_push(if_stmt->body->items, anode_string_literal_new(*segs));
				segs++;
			}
			twl_printf("fi node: %s\n", *segs);
		}
		segs++;
	}
	twl_printf("\n======\n");

	// t_anode_compound_stmt	*anode_compound_stmt;

	// anode_compound_stmt = anode_compound_stmt_new();
	// twl_lst_push(ast->root->items, anode_if_stmt_new());
	// twl_lst_push(ast->root->items, anode_if_stmt_new());
	// twl_lst_push(ast->root->items, anode_compound_stmt);
	// twl_lst_push(anode_compound_stmt->items, anode_if_stmt_new());
	// twl_lst_push(anode_compound_stmt->items, anode_if_stmt_new());
	// twl_lst_push(anode_compound_stmt->items, anode_if_stmt_new());
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
