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

static void			ast_build_cmd_stmt_push_fn(void *str, void *cmd_stmt_)
{
	t_string_literal	*str_lit;
	t_cmd_stmt			*cmd_stmt;
	char				*str_bis;

	str_bis = twl_strtrim(str);
	cmd_stmt = cmd_stmt_;
	str_lit = string_literal_new(str_bis);
	twl_lst_push(cmd_stmt->strings, str_lit);
	free(str_bis);
}

int					cmd_stmt_build(t_cmd_stmt *cmd_stmt, char *str)
{
	t_lst			*segs;

	segs = str_split_except_quote(str);
	twl_lst_iter(segs, ast_build_cmd_stmt_push_fn, cmd_stmt);
	return (twl_strlen(str));
}
