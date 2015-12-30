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

#include "ast/nodes/ast_andor_item.h"
#include "ast/nodes/ast_list_item.h"

static t_lst		*get_split_strings(void)
{
	static t_lst	*split_strings = NULL;

	if (split_strings == NULL)
	{
		split_strings = twl_str_split_to_lst("|", "_");
	}
	return (split_strings);
}

static int				build_ast_list_item(
								t_ast_andor_item *ast_andor_item,
								t_lst *tokens_tmp)
{
	t_token						*sep;
	t_ast_pipe_item				*ast_pipe_item;

	if (twl_lst_find(get_split_strings(), twl_strequ_void, token_mgr_last(tokens_tmp)->text))
		sep = twl_lst_pop(tokens_tmp);
	else
		sep = NULL;
	ast_pipe_item = ast_pipe_item_new_from_tokens(tokens_tmp, sep);
	if (ast_pipe_item == NULL)
		return (-1);
	twl_lst_push(ast_andor_item->ast_pipe_items, ast_pipe_item);
	return (0);
}

t_ast_andor_item	*ast_andor_item_new_from_tokens(t_lst *tokens, t_token *sep)
{
	t_ast_andor_item			*ast_andor_item;
	t_lst						*tokens_list;
	t_lst						*tokens_tmp;

	ast_andor_item = ast_andor_item_new();
	ast_andor_item->separator = sep;
	tokens_list = token_mgr_split(tokens, get_split_strings());
	while ((tokens_tmp = twl_lst_shift(tokens_list)))
	{
		if (build_ast_list_item(ast_andor_item, tokens_tmp) == -1)
			return (NULL);
	}
	return (ast_andor_item);
}
