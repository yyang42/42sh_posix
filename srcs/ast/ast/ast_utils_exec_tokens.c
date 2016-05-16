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

void				ast_utils_exec_tokens(t_lst *tokens)
{
	t_ast			*ast;

	ast = ast_new(tokens);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		shenv_singleton()->last_exit_code = 2;
	}
	ast_del(ast);
}
