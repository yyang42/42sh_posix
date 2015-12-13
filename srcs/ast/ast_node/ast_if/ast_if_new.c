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

#include "ast/nodes/ast_if.h"

t_ast_if			*ast_if_new(void)
{
	t_ast_if	*this;

	this = twl_malloc_x0(sizeof(t_ast_if));
	this->type = AST_IF;
	this->cond = ast_list_new();
	this->body = ast_list_new();
	this->elze = ast_list_new();
	return (this);
}
