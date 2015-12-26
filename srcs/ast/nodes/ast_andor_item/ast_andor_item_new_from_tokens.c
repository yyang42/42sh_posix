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

t_ast_andor_item	*ast_andor_item_new_from_tokens(t_lst *tokens)
{
	t_ast_andor_item		*ast_andor_item;
	t_token					*token;

	ast_andor_item = ast_andor_item_new();
	while (twl_lst_len(tokens))
	{
		twl_lst_push(ast_andor_item->ast_cmd_seq_lst, ast_cmd_seq_new_from_tokens(tokens));
		token = twl_lst_first(tokens);
		if (!token)
			break ;
		if (ast_cmd_seq_is_delimiter(token))
			twl_lst_shift(tokens);
		else
			break ;
	}
	return (ast_andor_item);
}
