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

t_ast_andor_item			*ast_andor_item_new(void)
{
	t_ast_andor_item		*ast_andor_item;

	ast_andor_item = twl_malloc_x0(sizeof(t_ast_andor_item));
	ast_andor_item->tokens = twl_lst_new();
	ast_andor_item->ast_pipe_item_lst = twl_lst_new();
	return (ast_andor_item);
}
