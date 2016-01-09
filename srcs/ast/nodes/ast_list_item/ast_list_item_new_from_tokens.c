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

#include "token/token_list_mgr.h"
#include "token/token_mgr.h"
#include "ast/nodes/ast_list_item.h"
#include "ast/ast.h"
#include "data.h"

static int			build_ast_andor_item(
								t_ast_list_item *ast_list_item,
								t_lst *tokens_tmp,
								struct s_ast *ast)
{
	t_token						*sep;
	t_ast_andor_item			*ast_andor_item;

	if (twl_lst_find(data_andor_separators(), twl_strequ_void,
		token_mgr_last(tokens_tmp)->text))
		sep = twl_lst_pop(tokens_tmp);
	else
		sep = NULL;
	if (twl_lst_len(tokens_tmp) == 0)
	{
		if (sep)
			ast_set_error_msg_format(ast, sep, "Unexpected token '%s'",
				sep->text);
		else
			ast_set_error_msg_syntax_error(ast);
		return (-1);
	}
	ast_andor_item = ast_andor_item_new_from_tokens(tokens_tmp, sep, ast);
	if (ast_andor_item == NULL)
		return (-1);
	twl_lst_push(ast_list_item->ast_andor_items, ast_andor_item);
	return (0);
}

static void			build_ast_andor_item_fn(void *tokens_tmp,
	void *ast_list_item, void *last_token_, void *ast)
{
	t_token			*last_token;

	last_token = last_token_;
	if (ast_has_error(ast))
		return ;
	if (twl_lst_len(tokens_tmp) == 0)
	{
		ast_set_error_msg_format(ast, last_token,
			"Expected input after '%s' but found nothing", last_token->text);
		return ;
	}
	build_ast_andor_item(ast_list_item, tokens_tmp, ast);
}

t_ast_list_item		*ast_list_item_new_from_tokens(t_lst *tokens, t_token *sep,
	struct s_ast *ast)
{
	t_ast_list_item				*ast_list_item;
	t_lst						*tokens_list;

	ast_list_item = ast_list_item_new();
	ast_list_item->separator = sep;
	tokens_list = token_mgr_split_ast(tokens, data_andor_separators(), true);
	twl_lst_iter3(tokens_list, build_ast_andor_item_fn, ast_list_item,
		twl_lst_last(tokens), ast);
	token_list_mgr_del(tokens_list);
	if (ast_has_error(ast))
	{
		ast_list_item_del(ast_list_item);
		return (NULL);
	}
	return (ast_list_item);
}
