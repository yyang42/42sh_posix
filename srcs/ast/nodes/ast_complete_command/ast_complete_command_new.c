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

t_ast_complete_command			*ast_complete_command_new(void)
{
	t_ast_complete_command		*ast_complete_command;

	ast_complete_command = twl_malloc_x0(sizeof(t_ast_complete_command));
	ast_complete_command->ast_and_or_seq_lst = twl_lst_new();
	return (ast_complete_command);
}
