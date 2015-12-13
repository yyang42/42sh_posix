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

#include "ast/nodes/ast_andor.h"

t_ast_andor				*ast_andor_new(t_ast_andor_type ast_andor_type)
{
	t_ast_andor	*this;

	this = twl_malloc_x0(sizeof(t_ast_andor));
	this->type = ANDOR;
	this->ast_andor_type = ast_andor_type;
	this->left = NULL;
	this->right = NULL;
	return (this);
}
