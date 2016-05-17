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

int					ast_utils_try_exec_string(char *input)
{
	t_ast			*ast;
	int				ret;

	ast = ast_new_from_string(input, 0);
	ret = 0;
	if (twl_lst_len(ast->ast_open_stack) == 0)
	{
		ast_print_error(ast);
	}
	else
	{
		ret = -1;
	}
	ast_del(ast);
	return (ret);
}
