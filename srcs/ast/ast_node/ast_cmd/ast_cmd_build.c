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

#include "ast/nodes/ast_cmd.h"
#include "ast/nodes/string_literal.h"

static void			ast_build_ast_cmd_push_fn(void *str, void *prev, void *ast_cmd_)
{
	t_string_literal	*str_lit;
	t_ast_cmd			*ast_cmd;
	char				*str_bis;
	char				*prev_bis;

	str_bis = twl_strtrim(str);
	prev_bis = prev ? twl_strtrim(prev) : NULL;
	ast_cmd = ast_cmd_;
	str_lit = string_literal_build(str_bis, NULL);
	if (twl_strequ(prev_bis, "<"))
		twl_lst_push(ast_cmd->redir_in, str_lit);
	else if (twl_strequ(prev_bis, ">"))
		twl_lst_push(ast_cmd->redir_out, str_lit);
	else if (!twl_strequ(str_bis, "<") && !twl_strequ(str_bis, ">"))
		twl_lst_push(ast_cmd->strings, str_lit);
	free(str_bis);
	free(prev_bis);
	(void)prev;
}

t_ast_cmd			*ast_cmd_build(char *str, int *len_ptr)
{
	t_lst			*segs;
	t_ast_cmd		*ast_cmd;

	ast_cmd = ast_cmd_new();
	segs = str_split_except_quote(str);
	twl_lst_iterp(segs, ast_build_ast_cmd_push_fn, ast_cmd);
	increment_len(len_ptr, twl_strlen(str));
	return (ast_cmd);
}
