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

#include "ast/ast.h"
#include "token/token_mgr.h"

static int			build_flags(void)
{
	int				flags;

	flags = 0;
	if (shenv_singleton()->shenv_prog_flags & SHENV_FLAG_AST)
	{
		flags |= AST_FLAG_NO_EXEC;
	}
	return (flags);
}

void				ast_utils_exec_string_inner(char *input, int line)
{
	t_ast			*ast;

	// twl_printf("ast_new\n");
	ast = ast_new_from_string(input, build_flags(), line);
	ast_print_error(ast);
	// twl_printf("ast_del\n");
	ast_del(ast);
}
