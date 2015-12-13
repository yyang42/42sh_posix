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

#include "utils.h"

#include "ast/nodes/ast_if.h"
#include "ast/nodes/ast_cmd.h"
#include "ast/nodes/ast_string.h"

static void			ast_build_ast_if_parts_fn(void *str, void *ast_if_)
{
	t_ast_if		*ast_if;
	t_ast_cmd		*ast_cmd;

	ast_if = ast_if_;
	if (twl_str_starts_with(str, "if"))
	{
		ast_cmd = ast_cmd_build(str + twl_strlen("if"), NULL);
		twl_lst_push(ast_if->cond->items, ast_cmd);
	}
	else if (twl_str_starts_with(str, "then"))
	{
		ast_cmd = ast_cmd_build(str + twl_strlen("then"), NULL);
		twl_lst_push(ast_if->body->items, ast_cmd);
	}
	else if (twl_str_starts_with(str, "else"))
	{
		ast_cmd = ast_cmd_build(str + twl_strlen("else"), NULL);
		twl_lst_push(ast_if->elze->items, ast_cmd);
	}
}

t_ast_if			*ast_if_build(char *str, int *len_ptr)
{
	char			*fi_pos;
	char			*if_str;
	t_lst			*if_segs;
	t_ast_if		*ast_if;

	ast_if = ast_if_new();
	fi_pos = twl_strstr(str, AST_SEPARATOR"fi"AST_SEPARATOR);
	if_str = twl_strndup(str, fi_pos - str);
	if_str = twl_strtrim_chars_free(if_str, AST_SEPARATOR);
	if_segs = twl_str_split_to_lst(if_str, AST_SEPARATOR);
	twl_lst_iter(if_segs, ast_build_ast_if_parts_fn, ast_if);
	free(if_str);
	twl_lst_del(if_segs, free);
	increment_len(len_ptr, fi_pos + twl_strlen(AST_SEPARATOR"fi"AST_SEPARATOR) - str);
	return (ast_if);
}
