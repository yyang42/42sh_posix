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

#include "ast/nodes/ast_function_def.h"
#include "ast/nodes/ast_compound_command.h"

void									ast_function_def_del(
	t_ast_function_def *this)
{
	ast_compound_command_del(this->compound_command);
	// void							*name;
	// struct s_ast_compound_command	*compound_command;
	// t_lst							*redir_items;

	free(this->name);
	free(this);
}
