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

#include "ast/nodes/ast_redir.h"

t_ast_redir			*ast_redir_new(t_lst *tokens)
{
	t_ast_redir		*ast_redir;

	ast_redir = twl_malloc_x0(sizeof(t_ast_redir));
	ast_redir->io_number = IO_NUMBER_NOT_DEFINED;
	ast_redir->redir_tokens = twl_lst_copy(tokens, token_copy_void);
	return (ast_redir);
}
