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

#include "twl_stdlib.h"

#include "token_mgr.h"

#include "ast/nodes/ast_redir.h"

t_ast_redir	*ast_redir_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_redir		*ast_redir;

	ast_redir = ast_redir_new();
	ast_redir->tokens = twl_lst_copy(tokens, NULL);
	if (twl_lst_len(tokens) == 3)
	{
		ast_redir->io_number = twl_atoi(token_mgr_get(tokens, 0)->text);
	}
	if (twl_lst_len(tokens) >= 2)
	{
		ast_redir->operator = twl_strdup(token_mgr_get(tokens, -2)->text);
		ast_redir->param = twl_strdup(token_mgr_get(tokens, -1)->text);
	}
	return (ast_redir);
	(void)ast;
}
