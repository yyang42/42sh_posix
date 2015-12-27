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

t_ast_andor_item	*ast_andor_item_new_from_tokens(t_lst *tokens)
{
	t_ast_andor_item			*ast_andor_item;
	t_lst						*tokens_list;
	t_lst						*tokens_tmp;

	ast_andor_item = ast_andor_item_new();
	ast_andor_item->tokens = twl_lst_copy(tokens, NULL);
	tokens_list = token_mgr_split(tokens, get_split_strings());
	while ((tokens_tmp = twl_lst_shift(tokens_list)))
	{
		twl_lst_push(ast_andor_item->ast_pipe_item_lst, ast_pipe_item_new_from_tokens(tokens_tmp));
	}
	return (ast_andor_item);
}
