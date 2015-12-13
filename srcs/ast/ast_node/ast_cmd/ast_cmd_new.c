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

#include "ast/nodes/ast_cmd.h"

t_ast_cmd			*ast_cmd_new(void)
{
	t_ast_cmd	*this;

	this = twl_malloc_x0(sizeof(t_ast_cmd));
	this->type = CMD_STMT;
	this->strings = twl_lst_new();
	this->redir_in = twl_lst_new();
	this->redir_out = twl_lst_new();
	this->redir_append = twl_lst_new();
	this->redir_heredoc = twl_lst_new();
	return (this);
}
