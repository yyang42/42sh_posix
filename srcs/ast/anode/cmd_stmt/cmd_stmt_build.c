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

#include "ast/anode/cmd_stmt.h"
#include "ast/anode/string_literal.h"

static void			ast_build_cmd_stmt_push_fn(void *str, void *prev, void *cmd_stmt_)
{
	t_string_literal	*str_lit;
	t_cmd_stmt			*cmd_stmt;
	char				*str_bis;
	char				*prev_bis;

	str_bis = twl_strtrim(str);
	prev_bis = prev ? twl_strtrim(prev) : NULL;
	cmd_stmt = cmd_stmt_;
	str_lit = string_literal_build(str_bis, NULL);
	if (twl_strequ(prev_bis, "<"))
		twl_lst_push(cmd_stmt->redir_in, str_lit);
	else if (twl_strequ(prev_bis, ">"))
		twl_lst_push(cmd_stmt->redir_out, str_lit);
	else if (!twl_strequ(str_bis, "<") && !twl_strequ(str_bis, ">"))
		twl_lst_push(cmd_stmt->strings, str_lit);
	free(str_bis);
	free(prev_bis);
	(void)prev;
}

t_cmd_stmt			*cmd_stmt_build(char *str, int *len_ptr)
{
	t_lst			*segs;
	t_cmd_stmt		*cmd_stmt;

	cmd_stmt = cmd_stmt_new();
	segs = str_split_except_quote(str);
	twl_lst_iterp(segs, ast_build_cmd_stmt_push_fn, cmd_stmt);
	increment_len(len_ptr, twl_strlen(str));
	return (cmd_stmt);
}
