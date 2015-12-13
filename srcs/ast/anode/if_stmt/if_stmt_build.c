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

#include "ast/anode/if_stmt.h"
#include "ast/anode/cmd_stmt.h"
#include "ast/anode/string_literal.h"

static void			ast_build_if_stmt_parts_fn(void *str, void *if_stmt_)
{
	t_if_stmt		*if_stmt;
	t_cmd_stmt		*cmd_stmt;

	if_stmt = if_stmt_;
	if (twl_str_starts_with(str, "if"))
	{
		cmd_stmt = cmd_stmt_build(str + twl_strlen("if"), NULL);
		twl_lst_push(if_stmt->cond->items, cmd_stmt);
	}
	else if (twl_str_starts_with(str, "then"))
	{
		cmd_stmt = cmd_stmt_build(str + twl_strlen("then"), NULL);
		twl_lst_push(if_stmt->body->items, cmd_stmt);
	}
	else if (twl_str_starts_with(str, "else"))
	{
		cmd_stmt = cmd_stmt_build(str + twl_strlen("else"), NULL);
		twl_lst_push(if_stmt->elze->items, cmd_stmt);
	}
}

t_if_stmt			*if_stmt_build(char *str, int *len_ptr)
{
	char			*fi_pos;
	char			*if_str;
	t_lst			*if_segs;
	t_if_stmt		*if_stmt;

	if_stmt = if_stmt_new();
	fi_pos = twl_strstr(str, AST_SEPARATOR"fi"AST_SEPARATOR);
	if_str = twl_strndup(str, fi_pos - str);
	if_str = twl_strtrim_chars_free(if_str, AST_SEPARATOR);
	if_segs = twl_str_split_to_lst(if_str, AST_SEPARATOR);
	twl_lst_iter(if_segs, ast_build_if_stmt_parts_fn, if_stmt);
	free(if_str);
	twl_lst_del(if_segs, free);
	increment_len(len_ptr, fi_pos + twl_strlen(AST_SEPARATOR"fi"AST_SEPARATOR) - str);
	return (if_stmt);
}
