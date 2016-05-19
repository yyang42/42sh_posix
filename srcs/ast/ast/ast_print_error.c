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

void				ast_print_error(t_ast *ast)
{
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		shenv_singleton()->last_exit_code = 2;
		shenv_singleton()->shenv_has_syntax_error = true;
		if (shenv_singleton()->shenv_prog_flags & SHENV_FLAG_EXIT_ON_AST_ERROR)
			exit(2);
	}
}
