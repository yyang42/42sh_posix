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

#include "data.h"
#include "token_mgr.h"
#include "openclose_matcher.h"

static bool			is_redirect_token(t_token *token)
{
	return (twl_lst_find(data_redir_operators(), twl_strequ_void, token->text));
}

static void			do_extract(t_lst *tokens, t_lst *tokens_list, t_lst *remaining_tokens)
{
	t_token			*token;
	t_lst			*redir;

	while ((token = twl_lst_first(tokens)))
	{
		if (is_redirect_token(token))
		{
			redir = twl_lst_new();
			twl_lst_push_back(redir, twl_lst_pop_front(tokens));
			if (twl_lst_len(tokens))
			{
				twl_lst_push_back(redir, twl_lst_pop_front(tokens));
			}
			twl_lst_push_back(tokens_list, redir);
		}
		else
		{
			twl_lst_push_back(remaining_tokens, twl_lst_pop_front(tokens));
		}
	}
}

t_lst				*token_mgr_extract_redir(t_lst *tokens)
{
	t_lst			*tokens_list;
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_clear(tokens, NULL);
	tokens_list = twl_lst_new();
	do_extract(tokens_copy, tokens_list, tokens);
	(void)tokens_copy;
	return (tokens_list);
}
