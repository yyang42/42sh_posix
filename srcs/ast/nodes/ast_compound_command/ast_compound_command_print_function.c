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

static t_compound_command_print_function_fn		*get_print_function_fns(void)
{
	static t_compound_command_print_function_fn	fns[COMPOUND_COMMAND_NBR];
	static bool									already_loaded = false;

	if (already_loaded == false)
	{
		fns[COMPOUND_COMMAND_BRACE_GROUP] = ast_brace_group_print_function_void;
		fns[COMPOUND_COMMAND_SUBSHELL] = ast_subshell_print_function_void;
		fns[COMPOUND_COMMAND_FOR_CLAUSE] = ast_for_clause_print_function_void;
		fns[COMPOUND_COMMAND_CASE_CLAUSE] = ast_case_clause_print_function_void;
		fns[COMPOUND_COMMAND_IF_CLAUSE] = ast_if_clause_print_function_void;
		fns[COMPOUND_COMMAND_WHILE_CLAUSE] =
			ast_while_clause_print_function_void;
		//fns[COMPOUND_COMMAND_UNTIL_CLAUSE] = ast_until_clause_print_function;
		already_loaded = true;
	}
	return (fns);
}

void									ast_compound_command_print_function(
						t_ast_compound_command *this, int depth)
{
	if (this->command_type != COMPOUND_COMMAND_NONE)
	{
		get_print_function_fns()[this->command_type](this->command, depth);
		if (twl_lst_len(this->redir_items) > 0)
		{
			twl_putchar(' ');
			ast_redir_print_function_list(this->redir_items);
		}
	}
}
