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

char				*ast_utils_check_open(char *input)
{
	t_ast			*ast;
	char			*open;

	ast = ast_new_from_string(input, 0, 1);
	open = NULL;
	if (twl_lst_len(ast->ast_open_stack) > 0)
	{
		open = twl_strdup(twl_lst_last(ast->ast_open_stack));
	}
	ast_del(ast);
	return (open);
}
