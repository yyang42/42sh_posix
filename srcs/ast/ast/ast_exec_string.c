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

int					ast_exec_string(char *input)
{
	t_ast			*ast;
	int				exit_code;

	ast = ast_new(input);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		exit_code = 1;
	}
	else
	{
		exit_code = ast_exec(ast);
	}
	ast_del(ast);
	return (exit_code);
}
