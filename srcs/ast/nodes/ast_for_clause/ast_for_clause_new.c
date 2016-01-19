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

#include "ast/nodes/ast_for_clause.h"

t_ast_for_clause			*ast_for_clause_new(void)
{
	t_ast_for_clause		*ast_for_clause;

	ast_for_clause = twl_malloc_x0(sizeof(t_ast_for_clause));
	ast_for_clause->wordlist = twl_lst_new();
	return (ast_for_clause);
}
