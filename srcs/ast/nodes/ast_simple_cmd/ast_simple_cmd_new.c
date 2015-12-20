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

#include "twl_xstdlib.h"

#include "ast/nodes/ast_simple_cmd.h"

t_ast_simple_cmd	*ast_simple_cmd_new(void)
{
	t_ast_simple_cmd	*this;

	this = twl_malloc_x0(sizeof(t_ast_simple_cmd));
	this->type = AST_SIMPLE_CMD;
	this->index = 0;
	return (this);
}
