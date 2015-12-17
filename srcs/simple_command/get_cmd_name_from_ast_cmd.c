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

char  *get_cmd_name_from_ast_cmd(t_ast_cmd *ast_cmd)
{
	t_ast_cmd_field	*cmd_field;
	t_ast_string	*string;

	cmd_field = twl_lst_first(ast_cmd->strings);
	string = twl_lst_first(cmd_field->items);
	return (string->text);
}
