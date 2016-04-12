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

#include "ast/nodes/ast_list_item.h"

void				ast_list_item_exec(t_ast_list_item *ast_list_item)
{
	if (token_mgr_last_equ(ast_list_item->list_item_tokens, "&"))
	{
		ast_list_item_exec_async(ast_list_item);
	}
	else
	{
		ast_list_item_exec_non_async(ast_list_item);
	}
}
