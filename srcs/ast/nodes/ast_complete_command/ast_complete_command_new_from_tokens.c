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

#include "ast/nodes/ast_complete_command.h"

static t_lst			*get_split_strings(void)
{
	static t_lst	*split_strings = NULL;

	if (split_strings == NULL)
	{
		split_strings = twl_str_split_to_lst(";_&_\n", "_");
	}
	return (split_strings);
}

t_ast_complete_command	*ast_complete_command_new_from_tokens(t_lst *tokens)
{
	t_ast_complete_command		*ast_complete_command;
	t_lst						*tokens_list;
	t_lst						*tokens_tmp;

	tokens_list = token_mgr_split(tokens, get_split_strings());
	ast_complete_command = ast_complete_command_new();
	while ((tokens_tmp = twl_lst_shift(tokens_list)))
	{
		if (twl_lst_len(tokens_tmp) > 0)
		{
			twl_lst_push(ast_complete_command->ast_list_item_lst, ast_list_item_new_from_tokens(tokens_tmp));
		}
	}
	return (ast_complete_command);
}
