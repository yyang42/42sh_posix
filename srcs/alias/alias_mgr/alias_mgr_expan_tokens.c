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

static char			*expan_token(t_token *token, t_lst *accumulator, t_htab *aliases, t_ast *ast)
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
			tokenizer_del(tokenizer);
			return (NULL);
		}
		twl_lst_extend(accumulator, tokenized_tokens);
		if (ast)
		{
			twl_lst_extend(ast->tokens_ref_tracker, tokenized_tokens);
		}
		twl_lst_del(tokenized_tokens, NULL);
		tokenizer_del(tokenizer);
		return (found);
	}
	return (NULL);
}

void				alias_mgr_expan_tokens(t_htab *aliases, t_lst *tokens, t_ast *ast)
{
	t_lst			*copy_tokens;
	t_token			*token;
	char			*alias;
	t_lst			*accumulator;

	copy_tokens = twl_lst_copy(tokens, NULL);
	accumulator = twl_lst_new();
	while (true)
	{
		token = twl_lst_pop_front(copy_tokens);
		if (!token || is_command_separator(token->text))
			break ;
		alias = expan_token(token, accumulator, aliases, ast);
		if (alias)
		{
			twl_lst_pop_front(tokens);
			if (twl_str_ends_with(alias, " ") && twl_lst_len(copy_tokens))
				continue ;
		}
		break ;
	}
	twl_lst_extend_front(tokens, accumulator);
	twl_lst_del(accumulator, NULL);
}
