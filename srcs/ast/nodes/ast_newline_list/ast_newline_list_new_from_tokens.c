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

#include "ast/nodes/ast_newline_list.h"

t_ast_newline_list	*ast_newline_list_new_from_tokens(t_lst *tokens)
{
	t_ast_newline_list		*ast_newline_list;

	ast_newline_list = ast_newline_list_new();
	twl_lst_shift(tokens);
	while (ast_newline_list_is_own_type(tokens))
	{
		twl_lst_shift(tokens);
		ast_newline_list->ast_newline_list = ast_newline_list_new_from_tokens(tokens);
	}
	return (ast_newline_list);
	(void)tokens;
}
