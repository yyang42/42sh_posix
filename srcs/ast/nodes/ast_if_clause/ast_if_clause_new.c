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

#include "ast/nodes/ast_if_clause.h"

t_ast_if_clause			*ast_if_clause_new(void)
{
	t_ast_if_clause		*ast_if_clause;

	ast_if_clause = twl_malloc_x0(sizeof(t_ast_if_clause));
	ast_if_clause->if_then_list = twl_lst_new();
	return (ast_if_clause);
}
