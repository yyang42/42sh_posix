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

#include "data.h"

#include "ast/nodes/ast_compound_list.h"

static int				build_ast_list_item(
								t_ast_compound_list *ast_compound_list,
								t_lst *tokens_tmp,
								struct s_ast *ast)
{
	t_token						*sep;
	t_ast_list_item				*ast_list_item;

	if (twl_lst_find(data_separators(), twl_strequ_void, token_mgr_last(tokens_tmp)->text))
		sep = twl_lst_pop(tokens_tmp);
	else
		sep = NULL;
	ast_list_item = ast_list_item_new_from_tokens(tokens_tmp, sep, ast);
	if (ast_list_item == NULL)
		return (-1);
	twl_lst_push(ast_compound_list->ast_list_items, ast_list_item);
	return (0);
}

t_ast_compound_list	*ast_compound_list_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_compound_list			*ast_compound_list;
	t_lst						*tokens_list;
	t_lst						*tokens_tmp;

	tokens_list = token_mgr_split(tokens, data_separators());
	ast_compound_list = ast_compound_list_new();
	while ((tokens_tmp = twl_lst_pop_front(tokens_list)))
	{
		// token_mgr_print(tokens_tmp);
		if (twl_lst_len(tokens_tmp) == 0)
			continue ;
		if (twl_lst_len(tokens_tmp) == 1
			&& twl_strequ(token_mgr_first(tokens_tmp)->text, "\n"))
			continue ;
		if (build_ast_list_item(ast_compound_list, tokens_tmp, ast) == -1)
			return (NULL);
	}
	return (ast_compound_list);
	(void)ast;
}
