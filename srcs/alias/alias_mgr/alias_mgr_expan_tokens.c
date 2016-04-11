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

#include "alias/alias_mgr.h"
#include "logger.h"
#include "data_utils.h"
#include "token/token_mgr.h"
#include "token/tokenizer.h"

static bool			is_command_separator(char *str)
{
	return (data_utils_is_control_operators_nl(str)
		|| data_utils_is_reserved_word(str));
}

static void			expan_token(t_token *token, t_lst *res_tokens, t_htab *aliases)
{
	char			*found;
	t_lst			*tokenized_tokens;
	t_tokenizer		*tokenizer;

	found = twl_htab_get(aliases, token->text);
	if (found)
	{
		tokenizer = tokenizer_new(found);
		tokenized_tokens = tokenizer_tokenize(tokenizer);
		if (tokenizer->err_msg)
		{
			twl_dprintf(2, "%s\n", tokenizer->err_msg);
			exit(2);
		}
		twl_lst_extend(res_tokens, tokenized_tokens);
		twl_lst_del(tokenized_tokens, NULL);
	}
	else
	{
		twl_lst_push_back(res_tokens, token_copy(token));
	}
}

t_lst				*alias_mgr_expan_tokens(t_htab *aliases, t_lst *tokens)
{
	t_lst			*copy_tokens;
	t_token			*token;
	t_lst			*res_tokens;

	res_tokens = twl_lst_new();
	copy_tokens = twl_lst_copy(tokens, NULL);
	while ((token = twl_lst_pop_front(copy_tokens)))
	{
		if (is_command_separator(token->text))
		{
			twl_lst_push_back(res_tokens, token_copy(token));
			continue ;
		}
		expan_token(token, res_tokens, aliases);
		while (token_mgr_first(copy_tokens)
			&& !is_command_separator(token_mgr_first(copy_tokens)->text))
		{
			twl_lst_push_back(res_tokens, token_copy(twl_lst_pop_front(copy_tokens)));
		}
	}
	twl_lst_del(copy_tokens, NULL);
	return (res_tokens);
}
