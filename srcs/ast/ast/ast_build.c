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
#include "utils.h"

static bool			is_if_stmt(char *str)
{
	if (twl_str_starts_with(str, "if "))
		return (true);
	else
		return (false);
}

static void			ast_build_cmd_stmt_push_fn(void *str, void *cmd_stmt_)
{
	t_string_literal	*str_lit;
	t_cmd_stmt			*cmd_stmt;

	cmd_stmt = cmd_stmt_;
	str_lit = string_literal_new(str);
	twl_lst_push(cmd_stmt->strings, str_lit);
}

static int			ast_build_cmd_stmt(t_cmd_stmt *cmd_stmt, char *str)
{
	t_lst			*segs;

	segs = str_split_except_quote(str);
	twl_lst_iter(segs, ast_build_cmd_stmt_push_fn, cmd_stmt);
	return (twl_strlen(str));
}

static void			ast_build_if_stmt_parts_fn(void *str, void *if_stmt_)
{
	t_if_stmt		*if_stmt;
	t_cmd_stmt		*cmd_stmt;

	if_stmt = if_stmt_;
	if (twl_str_starts_with(str, "if "))
	{
		cmd_stmt = cmd_stmt_new();
		ast_build_cmd_stmt(cmd_stmt, str + twl_strlen("if "));
		twl_lst_push(if_stmt->cond->items, cmd_stmt);
	}
	else if (twl_str_starts_with(str, "then "))
	{
		cmd_stmt = cmd_stmt_new();
		ast_build_cmd_stmt(cmd_stmt, str + twl_strlen("then "));
		twl_lst_push(if_stmt->body->items, cmd_stmt);
	}
	else if (twl_str_starts_with(str, "else "))
	{
		cmd_stmt = cmd_stmt_new();
		ast_build_cmd_stmt(cmd_stmt, str + twl_strlen("else "));
		twl_lst_push(if_stmt->elze->items, cmd_stmt);
	}
}

static int			ast_build_if_stmt(t_if_stmt *if_stmt, char *str)
{
	char			*fi_pos;
	char			*if_str;
	t_lst			*if_segs;

	fi_pos = twl_strstr(str, ";fi;");
	if_str = twl_strndup(str, fi_pos - str);
	if_str = twl_strtrim_chars_free(if_str, ";");
	if_segs = twl_str_split_to_lst(if_str, ';');
	// twl_printf("====> if        %s\n", str);
	// twl_printf("====> after fi  %s\n", twl_strstr(str, "fi"));
	// twl_printf("====> if_str    %s\n", if_str);
	// twl_printf("====> fi_pos    %s\n", fi_pos);
	twl_lst_iter(if_segs, ast_build_if_stmt_parts_fn, if_stmt);

	(void)str;
	(void)if_stmt;
	free(if_str);
	twl_lst_del(if_segs, free);
	return (fi_pos + twl_strlen(";fi;") - str);
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
		int	len = ast_build_cmd_stmt(cmd_stmt, not_comp_stmt);
		return (len + twl_strlen(";"));
	}
	assert(!"Should not reach here!");
}

static int			ast_build_compound_stmt(t_compound_stmt *compound_stmt, char *str)
{
	int				len;
	int				total_len;

	total_len = twl_strlen(str);
	len = 0;
	while (len < total_len)
	{
		COUCOU;
		if (is_if_stmt(str + len))
		{
			t_if_stmt *if_stmt;
			if_stmt = if_stmt_new();
			COUCOU;
			twl_lst_push(compound_stmt->items, if_stmt);
			COUCOU;
			len += ast_build_if_stmt(if_stmt, str + len);
			COUCOU;
		}
		else
		{
			COUCOU;
			len += ast_build_compound_stmt_lists(compound_stmt, str + len);
			COUCOU;
		}
		COUCOU;
	}
	(void)compound_stmt;
	(void)str;
	return (0);
}

void				ast_build(t_ast *ast)
{
	ast->root = compound_stmt_new();
	ast_build_compound_stmt(ast->root, ast->raw);
}
