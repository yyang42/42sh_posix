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

#include "ast/nodes/ast_simple_command.h"

t_ast_simple_command			*ast_simple_command_new(void)
{
	t_ast_simple_command		*ast_simple_command;

	ast_simple_command = twl_malloc_x0(sizeof(t_ast_simple_command));
	ast_simple_command->cmd_tokens_deep_copy = NULL;
	ast_simple_command->redir_items = twl_lst_new();
	ast_simple_command->assignment_items = NULL;
	ast_simple_command->redir_fds = twl_lst_new();
	return (ast_simple_command);
}
