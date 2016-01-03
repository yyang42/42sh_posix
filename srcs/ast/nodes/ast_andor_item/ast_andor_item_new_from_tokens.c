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

#include "token/token_mgr.h"

#include "ast/ast.h"
#include "ast/nodes/ast_andor_item.h"
#include "ast/nodes/ast_list_item.h"

static void				build_ast_list_item(
								t_ast_andor_item *ast_andor_item,
								t_lst *tokens_tmp,
								struct s_ast *ast)
{
	t_token						*sep;
	t_ast_pipe_item				*ast_pipe_item;

	sep = NULL;
	if (token_mgr_last_equ(tokens_tmp, "|"))
		sep = twl_lst_pop(tokens_tmp);
	if (twl_lst_len(tokens_tmp) == 0)
	{
		if (sep)
			ast_set_error_msg_format(ast, sep, "Unexpected token '%s'", sep->text);
		else
			ast_set_error_msg_syntax_error(ast);
		return ;
	}
	ast_pipe_item = ast_pipe_item_new_from_tokens(tokens_tmp, sep, ast);
	if (ast_pipe_item == NULL)
		return ;
	twl_lst_push(ast_andor_item->ast_pipe_items, ast_pipe_item);
}

static void			build_ast_list_item_fn(void *tokens_tmp,
	void *ast_andor_item, void *last_token, void *ast)
{
	if (ast_has_error(ast))
		return ;
	if (twl_lst_len(tokens_tmp) == 0)
	{
		ast_set_error_msg_format(ast, last_token,
			"Expected input after '|' but found nothing");
		return ;
	}
	build_ast_list_item(ast_andor_item, tokens_tmp, ast);
}

t_ast_andor_item	*ast_andor_item_new_from_tokens(t_lst *tokens, t_token *sep, struct s_ast *ast)
{
	t_ast_andor_item			*ast_andor_item;
	t_lst						*tokens_list;

	ast_andor_item = ast_andor_item_new();
	ast_andor_item->separator = sep;
	tokens_list = token_mgr_split_by_one_sep(tokens, "|", true);
	twl_lst_iter3(tokens_list, build_ast_list_item_fn, ast_andor_item, twl_lst_last(tokens), ast);
	if (ast_has_error(ast))
	{
		ast_andor_item_del(ast_andor_item);
		return (NULL);
	}
	return (ast_andor_item);
}
