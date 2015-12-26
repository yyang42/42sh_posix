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

#include <stdlib.h>

#include "ast/ast.h"
#include "token_mgr.h"

static char			*get_list_text(t_ast2_list *list)
{
	t_token			*token;
	char			*out;

	out = twl_strdup("list");
	token = twl_lst_first(list->tokens);
	if (token)
	{
		out = twl_strjoinfree(out, " ", 'l');
		out = twl_strjoinfree(out, token->text, 'l');
	}
	return (out);
}

void				ast_str_append_list(t_ast *ast, t_ast2_list *list)
{
	char			*text;

	text = get_list_text(list);
	ast_str_push_line(ast, text, 0);
	ast->out_depth++;
	if (list->list)
		ast_str_append_list(ast, list->list);
	ast->out_depth--;
	free(text);
}
