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

#include "ast/nodes/ast_brace_group.h"

t_ast_brace_group			*ast_brace_group_new(void)
{
	t_ast_brace_group		*ast_brace_group;

	ast_brace_group = twl_malloc_x0(sizeof(t_ast_brace_group));
	ast_brace_group->ast_compound_list = NULL;
	return (ast_brace_group);
}
