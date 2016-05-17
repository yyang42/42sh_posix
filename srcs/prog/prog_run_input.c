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

#include "prog.h"
#include "ast/ast.h"

void				prog_run_input(t_prog *prog, char *input, int line)
{
	if (shenv_singleton()->shenv_prog_flags & SHENV_FLAG_AST)
	{
		prog_print_ast(prog, input);
	}
	else if (shenv_singleton()->shenv_prog_flags & SHENV_FLAG_AREXP)
	{
		prog_print_arexp(prog, input);
	}
	else
	{
		ast_utils_exec_string(input, line);
	}
}
