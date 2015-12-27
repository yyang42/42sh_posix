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

#include "ast/nodes/ast_subshell.h"
#include "ast/nodes/ast_complete_command.h"

void				ast_subshell_print_rec(t_ast_subshell *ast_subshell, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_subshell\n");
	depth++;
	ast_complete_command_print_rec(ast_subshell->ast_complete_command, depth);
	// token_mgr_print(ast_subshell->tokens);
	// if (twl_strequ(twl_lst_first(ast_subshell->tokens), "(")
	// 	&& twl_strequ(twl_lst_last(ast_subshell->tokens), ")"))
	(void)ast_subshell;
}
