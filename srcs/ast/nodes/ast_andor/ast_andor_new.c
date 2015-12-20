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

#include "ast/nodes/ast_andor_seq.h"

t_ast_andor_seq				*ast_andor_seq_new(t_andor_type andor_type)
{
	t_ast_andor_seq	*this;

	this = twl_malloc_x0(sizeof(t_ast_andor_seq));
	this->type = AST_ANDOR_SEQ;
	this->andor_type = andor_type;
	this->left = NULL;
	this->right = NULL;
	this->pipes = twl_lst_new();
	this->index = 0;
	return (this);
}
