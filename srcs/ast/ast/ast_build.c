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

#include "ast/ast.h"

#include "twl_arr.h"
#include "twl_xstring.h"

static void			ast_build_do(t_ast *ast)
{

	// segs = twl_strsplit_mul_trim_chars(ast->raw, AST_SEPARATOR_OP,
	// 														AST_WHITE_SPACE);
	// twl_arr_putstr(segs, "\n");
	// twl_printf("\n======\n");
	// while (*segs)
	// {
	// 	if (twl_str_starts_with(*segs, "if "))
	// 	{
	// 		t_t_if_stmt 			*if_stmt = t_if_stmt_new();
	// 		twl_lst_push(ast->root->items, if_stmt);
	// 		if_stmt->body = compound_stmt_new();
	// 		if_stmt->cond = string_literal_new(*segs);
	// 		segs++;
	// 		while (!twl_str_starts_with(*segs, "fi"))
	// 		{
	// 			twl_lst_push(if_stmt->body->items, string_literal_new(*segs));
	// 			segs++;
	// 		}
	// 		twl_printf("fi node: %s\n", *segs);
	// 	}
	// 	segs++;
	// }
	// twl_printf("\n======\n");
	(void)ast;
}

void				ast_build(t_ast *ast)
{
	ast->root = compound_stmt_new();
	ast_build_do(ast);
}
