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

static void travel_ast_string(void *ast_node, void *ret)
{
	t_ast_string	*string;
	char			**temp;
	char 			*tmp;

	string = ast_node;
	temp = ret;
	tmp = *temp;
	if (tmp != NULL)
	{
		tmp = twl_strjoinfree(tmp, " ", 'l');
		tmp = twl_strjoinfree(tmp, string->text, 'l');
	}
	else
		tmp = twl_strdup(string->text);
	*temp = tmp;
	ret = temp;
}

static void travel_ast_cmd_field(void *ast_node, void *ret)
{
	t_ast_cmd_field *cmd_field;

	cmd_field = ast_node;
	twl_lst_iter(cmd_field->items, travel_ast_string, ret);
}

void concatenate_ast_cmd(t_lst *ast_nodes)
{
	char *ret;

	ret = NULL;
	twl_lst_iter(ast_nodes, travel_ast_cmd_field, &ret);
}
