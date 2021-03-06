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

#include "twl_xstdio.h"

#include "ast/ast.h"
#include "prog.h"

int					prog_utils_print_ast(char *input)
{
	t_ast			*ast;

	ast = ast_new_from_string(input, AST_FLAG_NO_EXEC, 1);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		ast_del(ast);
		return (1);
	}
	ast_print_rec(ast);
	ast_del(ast);
	return (0);
}
