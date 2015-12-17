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
#include "twl_arr.h"

static void travel_ast_string(void *ast_node, void *ret)
{
	t_ast_string	*string;
	char			**arr;

	string = ast_node;
	arr = ret;
	twl_arr_push(arr, twl_strdup(string->text));
}


static void travel_ast_cmd_field(void *ast_node, void *args)
{
	t_ast_cmd_field *cmd_field;

	cmd_field = ast_node;
	twl_lst_iter(cmd_field->items, travel_ast_string, args);
}

char  **get_cmd_args_from_ast_cmd(t_ast_cmd *ast_cmd)
{
	char			**args;

	args = twl_arr_new(twl_lst_len(ast_cmd->strings));
	twl_lst_iter(ast_cmd->strings, travel_ast_cmd_field, args);
	return (args);
}
