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

#include <stdlib.h>

#include "ast/ast.h"

void				ast_str_append_complete_command(t_ast *ast,
								t_ast2_complete_command *complete_command)
{
	ast_str_push_line(ast, "complete_command", 0);
	ast->out_depth++;
	ast_str_append_list(ast, complete_command->list);
	// twl_lst_iter(complete_command->andors, iter_andor_fn, ast);
	ast->out_depth--;
	// (void)complete_command;
	(void)complete_command;
}
