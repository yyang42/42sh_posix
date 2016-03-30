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

#include "builtin/cmds/builtin_eval.h"
#include "ast/ast.h"
#include "ast/nodes/ast_compound_list.h"

void				builtin_eval_exec_str(char *str)
{
	t_ast			*ast;

	ast = ast_new(str);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		shenv_singleton()->last_exit_code = ast_exec(ast);
	}
	ast_del(ast);
}
