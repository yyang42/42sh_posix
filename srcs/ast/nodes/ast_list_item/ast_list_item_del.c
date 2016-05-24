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

void				ast_list_item_del(t_ast_list_item *ast_list_item)
{
	if (!ast_list_item)
		return ;
	twl_lst_del(ast_list_item->ast_andor_items, ast_andor_item_del);
	if (ast_list_item->list_item_tokens_deep)
		token_mgr_del(ast_list_item->list_item_tokens_deep);
	token_del(ast_list_item->separator);
	free(ast_list_item);
}
