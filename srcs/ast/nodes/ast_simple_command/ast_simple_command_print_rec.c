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

#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

void				ast_simple_command_print_rec(t_ast_simple_command *this,
	int depth)
{
	char			*command_str;
	char			*joined_command;

	joined_command = token_mgr_strjoin(this->command_tokens, " ");
	command_str = twl_str_truncate(joined_command, 20);
	ast_print_indent(depth);
	twl_printf_escape_nl("ast_simple_command (%s)", command_str);
	twl_printf("\n");
	free(command_str);
	depth++;
	ast_redir_print_rec_list(this->redir_items, depth);
	ast_assignment_print_rec_list(this->assignment_items, depth);
	free(joined_command);
}
