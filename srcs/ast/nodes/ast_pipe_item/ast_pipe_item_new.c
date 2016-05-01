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

#include "ast/nodes/ast_pipe_item.h"

t_ast_pipe_item			*ast_pipe_item_new(void)
{
	t_ast_pipe_item		*this;

	this = twl_malloc_x0(sizeof(t_ast_pipe_item));
	this->pipe_write_end = -1;
	this->pipe_read_end = -1;
	return (this);
}
