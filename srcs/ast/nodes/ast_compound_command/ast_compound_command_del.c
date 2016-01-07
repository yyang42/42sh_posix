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

#include "ast/nodes/ast_compound_command.h"

static t_compound_command_print_del_fn	*get_print_del_fns(void)
{
	static t_compound_command_print_del_fn	fns[COMPOUND_COMMAND_NBR];
	static bool								already_loaded = false;

	if (already_loaded == false)
	{
		fns[COMPOUND_COMMAND_SUBSHELL] = ast_subshell_del_void;
		fns[COMPOUND_COMMAND_IF_CLAUSE] = ast_if_clause_del_void;
		fns[COMPOUND_COMMAND_BRACE_GROUP] = ast_brace_group_del_void;
	}
	return (fns);
}

void									ast_compound_command_del(
	t_ast_compound_command *this)
{
	if (this->command_type != COMPOUND_COMMAND_NONE)
	{
		if (this->command)
			get_print_del_fns()[this->command_type](this->command);
		twl_lst_del(this->redir_items, ast_redir_del_void);
	}
	free(this);
}
