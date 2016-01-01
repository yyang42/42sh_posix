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

#include "token_mgr.h"

#include "ast/ast.h"
#include "ast/nodes/ast_andor_item.h"
#include "ast/nodes/ast_list_item.h"

static int				build_ast_list_item(
								t_ast_andor_item *ast_andor_item,
								t_lst *tokens_tmp,
								struct s_ast *ast)
{
	t_token						*sep;
	t_ast_pipe_item				*ast_pipe_item;

	if (twl_strequ(token_mgr_last(tokens_tmp)->text, "|"))
		sep = twl_lst_pop(tokens_tmp);
	else
		sep = NULL;
	ast_pipe_item = ast_pipe_item_new_from_tokens(tokens_tmp, sep, ast);
	if (ast_pipe_item == NULL)
		return (-1);
	twl_lst_push(ast_andor_item->ast_pipe_items, ast_pipe_item);
	return (0);
}

t_ast_andor_item	*ast_andor_item_new_from_tokens(t_lst *tokens, t_token *sep, struct s_ast *ast)
{
	t_ast_andor_item			*ast_andor_item;
	t_lst						*tokens_list;
	t_lst						*tokens_tmp;

	ast_andor_item = ast_andor_item_new();
	ast_andor_item->separator = sep;
	tokens_list = token_mgr_split_by_one_sep(tokens, "|");
	while ((tokens_tmp = twl_lst_shift(tokens_list)))
	{
		if (twl_lst_len(tokens_tmp) == 0)
		{
			ast_set_error_msg_format(ast, token_mgr_last(tokens),
				"Expected input after '|' but found nothing");
			return (NULL);
		}
		if (build_ast_list_item(ast_andor_item, tokens_tmp, ast) == -1)
			return (NULL);
	}
	return (ast_andor_item);
}
