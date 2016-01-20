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

#include "ast/nodes/ast_function_def.h"
#include "ast/nodes/ast_compound_command.h"

void									ast_function_def_print_rec(
	t_ast_function_def *this, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_function_def (name=%s)\n", this->name);
	depth++;
	if (this->compound_command)
		ast_compound_command_print_rec(this->compound_command, depth);
}
