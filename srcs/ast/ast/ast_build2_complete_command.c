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

#include "twl_arr.h"
#include "utils.h"

t_ast2_complete_command *ast_build2_complete_command(t_ast *ast)
{
	t_ast2_complete_command		*complete_command;

	complete_command = ast2_complete_command_new();
	complete_command->list = ast_build2_list(ast);
	return (complete_command);
	(void)ast;
}
