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

bool				ast_utils_check_has_open(char *input)
{
	t_ast			*ast;
	bool			has_open;

	ast = ast_new_from_string(input, 0);
	has_open = (twl_lst_len(ast->ast_open_stack) > 0);
	ast_del(ast);
	return (has_open);
}
