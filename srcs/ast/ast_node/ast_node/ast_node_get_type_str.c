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

#include "ast/nodes/ast_node.h"

char				*ast_node_get_type_str(void *ast_node)
{
	if (ast_node_get_type(ast_node) == COMPOUND_STMT)
		return ("COMPOUND_STMT");
	else if (ast_node_get_type(ast_node) == IF_STMT)
		return ("IF_STMT");
	else if (ast_node_get_type(ast_node) == CMD_STMT)
		return ("CMD_STMT");
	else if (ast_node_get_type(ast_node) == STRING_LITERAL)
		return ("STRING_LITERAL");
	else if (ast_node_get_type(ast_node) == PIPELINE)
		return ("PIPELINE");
	else if (ast_node_get_type(ast_node) == ANDOR)
		return ("ANDOR");
	return ("NOT_FOUND");
}
