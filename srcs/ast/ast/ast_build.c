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

static bool			is_if_stmt(char *str)
{
	if (twl_str_starts_with(str, "if "))
		return (true);
	else
		return (false);
}

static int			ast_build_if_stmt(t_if_stmt *if_stmt, char *str)
{
	(void)str;
	(void)if_stmt;
	return (0);
}

static int			ast_build_cmd_stmt(t_cmd_stmt *cmd_stmt, char *str)
{
	(void)cmd_stmt;
	return (twl_strlen(str));
}

static int			ast_build_compound_stmt_lists(t_compound_stmt *compound_stmt, char *str)
{
	char				*not_comp_stmt;

	not_comp_stmt = twl_str_split_get(str, ";", 0);
	if ("TODO is_a_simple_cmd")
	{
		t_cmd_stmt	*cmd_stmt;
		cmd_stmt = cmd_stmt_new();
		twl_lst_push(compound_stmt->items, cmd_stmt);
		int	len = ast_build_cmd_stmt(cmd_stmt, str);
		return (len);
	}
	assert(!"Should not reach here!");
}

static int			ast_build_compound_stmt(t_compound_stmt *compound_stmt, char *str)
{
	if (is_if_stmt(str))
	{
		t_if_stmt *if_stmt;
		if_stmt = if_stmt_new();
		COUCOU;
		twl_lst_push(compound_stmt->items, if_stmt);
		COUCOU;
		ast_build_if_stmt(if_stmt, str);
	}
	else
	{
		ast_build_compound_stmt_lists(compound_stmt, str);
	}
	// segs = twl_strsplit_mul_trim_chars(ast->raw, AST_SEPARATOR_OP,
	// 														AST_WHITE_SPACE);
	// twl_arr_putstr(segs, "\n");
	// twl_printf("\n======\n");
	// while (*segs)
	// {
	// 	if (twl_str_starts_with(*segs, "if "))
	// 	{
	// 		t_if_stmt 			*if_stmt = if_stmt_new();
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
	(void)compound_stmt;
	(void)str;
	return (0);
}

void				ast_build(t_ast *ast)
{
	ast->root = compound_stmt_new();
	ast_build_compound_stmt(ast->root, ast->raw);
}
