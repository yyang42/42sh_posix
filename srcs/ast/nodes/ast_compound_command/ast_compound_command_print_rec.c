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

void				ast_compound_command_print_rec(t_ast_compound_command *ast_compound_command, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_compound_command");
	twl_printf(" %s", token_mgr_first(ast_compound_command->tokens)->text);
	twl_printf("\n");
	(void)ast_compound_command;
}
