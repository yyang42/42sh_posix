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

#include "ast/nodes/ast_command.h"
#include "token_mgr.h"

void				ast_command_print_rec(t_ast_command *ast_command, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_command %s\n", token_mgr_first(ast_command->tokens)->text);
	(void)ast_command;
}
