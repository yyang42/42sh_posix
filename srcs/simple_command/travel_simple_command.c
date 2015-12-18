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

#include "simple_command.h"

void travel_simple_command(void *ast_node,  void *cmd_)
{
	t_simple_command *cmd;

	cmd = cmd_;
	if (ast_node_get_type(ast_node) == AST_LIST)
	{
		t_ast_list		*ast_list = ast_node;
		twl_lst_iter(ast_list->items, travel_simple_command, cmd);
	}
	else if (ast_node_get_type(ast_node) == AST_CMD)
	{
		travel_ast_cmd(cmd, ast_node);
	}
}
