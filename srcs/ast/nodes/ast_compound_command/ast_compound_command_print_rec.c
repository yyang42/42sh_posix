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

#include "ast/nodes/ast_redir.h"

#include "ast/nodes/ast_compound_command.h"

static t_compound_command_print_rec_fn *get_print_rec_fns(void)
{
	static t_compound_command_print_rec_fn	fns[COMPOUND_COMMAND_NBR];
	static bool								already_loaded = false;

	if (already_loaded == false)
	{
		fns[COMPOUND_COMMAND_SUBSHELL] = ast_subshell_print_rec_void;
		fns[COMPOUND_COMMAND_IF_CLAUSE] = ast_if_clause_print_rec_void;
	}
	return (fns);
}

static void			iter_redir_rec_fn(void *ast_redir, void *depth_ptr)
{
	ast_redir_print_rec(ast_redir, *(int *)depth_ptr);
}

void				ast_compound_command_print_rec(t_ast_compound_command *ast_compound_command, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_compound_command\n");
	depth++;
	if (ast_compound_command->type != COMPOUND_COMMAND_NONE)
	{
		get_print_rec_fns()[ast_compound_command->type](ast_compound_command->command, depth);
		twl_lst_iter(ast_compound_command->redir_items, iter_redir_rec_fn, &depth);
	}
}
