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

#include "ast/nodes/ast_pipe_seq.h"

t_ast_pipe_seq			*ast_pipe_seq_new(void)
{
	t_ast_pipe_seq		*ast_pipe_seq;

	ast_pipe_seq = twl_malloc_x0(sizeof(t_ast_pipe_seq));
	ast_pipe_seq->tokens = twl_lst_new();
	ast_pipe_seq->ast_cmd_seq_lst = twl_lst_new();
	return (ast_pipe_seq);
}
