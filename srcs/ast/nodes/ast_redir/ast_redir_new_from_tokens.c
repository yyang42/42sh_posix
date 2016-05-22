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

#include "token/token_mgr.h"
#include "ast/nodes/ast_redir.h"
#include "ast/ast.h"

t_ast_redir	*ast_redir_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_redir		*this;
	t_token			*last_token;

	this = ast_redir_new(tokens);
	if (twl_lst_len(tokens) == 3)
	{
		this->io_number = twl_atoi(token_mgr_get(tokens, 0)->text);
	}
	if (twl_lst_len(tokens) >= 2)
	{
		this->operator = twl_strdup(token_mgr_get(tokens, -2)->text);
		this->param = token_copy(token_mgr_get(tokens, -1));
	}
	else
	{
		ast_set_error_msg_format_token(ast, token_mgr_first(tokens),
				"Expect argument after '%s'", token_mgr_first(tokens)->text);
		ast_redir_del(this);
		return (NULL);
	}
	last_token = token_mgr_get(tokens, -1);
	if (last_token->heredoc_text)
	{
		this->heredoc_text = twl_strdup(last_token->heredoc_text);
		this->heredoc_text_unexpanded = twl_strdup(this->heredoc_text);
	}
	return (this);
}
