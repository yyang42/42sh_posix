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

#include "token/token_mgr.h"
#include "token/tokenizer.h"
#include "ast/nodes/ast_redir.h"

void				tokenizer_delimit_handle_heredoc(t_tokenizer *t,
														t_token *new_token)
{
	t_token			*last_token;

	last_token = token_mgr_last(t->tokens);
	if (last_token && ast_redir_utils_is_heredoc(last_token->text))
	{
		new_token->heredoc_operator = twl_strdup(last_token->text);
		twl_lst_push_back(t->open_heredocs, new_token);
		twl_lst_push_back(t->tok_open_stack, new_token->text);
	}
}
