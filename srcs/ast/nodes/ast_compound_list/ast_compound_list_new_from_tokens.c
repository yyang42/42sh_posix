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

#include "ast/ast.h"
#include "data.h"

#include "ast/nodes/ast_compound_list.h"

static int			build_ast_list_item(
								t_ast_compound_list *ast_compound_list,
								t_lst *tokens_tmp,
								struct s_ast *ast)
{
	t_token						*sep;
	t_ast_list_item				*ast_list_item;

	if (twl_lst_find(data_list_separators(), twl_strequ_void,
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
	ast_list_item = ast_list_item_new_from_tokens(tokens_tmp, sep, ast);
	if (ast_list_item == NULL)
		return (-1);
	twl_lst_push(ast_compound_list->ast_list_items, ast_list_item);
	return (0);
}

static void			build_children_fn(void *tokens_tmp,
	void *this, void *ast)
{
	if (ast_has_error(ast))
		return ;
	if (twl_lst_len(tokens_tmp) == 0)
		return ;
	if (twl_lst_len(tokens_tmp) == 1
		&& twl_strequ(token_mgr_first(tokens_tmp)->text, "\n"))
		return ;
	build_ast_list_item(this, tokens_tmp, ast);
}

t_ast_compound_list	*ast_compound_list_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_compound_list			*this;
	t_lst						*tokens_list;

	tokens_list = token_mgr_split_ast(tokens, data_list_separators(), true);
	this = ast_compound_list_new();
	twl_lst_iter2(tokens_list, build_children_fn, this, ast);
	token_list_mgr_del(tokens_list);
	if (ast_has_error(ast))
	{
		ast_compound_list_del(this);
		return (NULL);
	}
	return (this);
}
