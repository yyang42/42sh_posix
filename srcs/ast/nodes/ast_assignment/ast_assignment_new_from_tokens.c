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

t_ast_assignment	*ast_assignment_new_from_tokens(char *key, char *value,
	struct s_ast *ast)
{
	t_ast_assignment		*ast_assignment;

	ast_assignment = ast_assignment_new();
	ast_assignment->key = twl_strdup(key);
	ast_assignment->value = value ? twl_strdup(value) : NULL;
	return (ast_assignment);
	(void)ast;
}
