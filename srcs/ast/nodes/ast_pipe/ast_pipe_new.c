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

#include "ast/nodes/ast_pipe.h"

t_ast_pipe			*ast_pipe_new(void)
{
	t_ast_pipe	*this;

	this = twl_malloc_x0(sizeof(t_ast_pipe));
	this->type = AST_PIPE;
	this->left = NULL;
	this->right = NULL;
	this->pipes = twl_lst_new();
	return (this);
}
