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

#include "ast/nodes/ast_compound_command.h"

t_ast_compound_command			*ast_compound_command_new(void)
{
	t_ast_compound_command		*ast_compound_command;

	ast_compound_command = twl_malloc_x0(sizeof(t_ast_compound_command));
	ast_compound_command->redir_items = twl_lst_new();
	ast_compound_command->redir_fds = twl_lst_new();
	return (ast_compound_command);
}
