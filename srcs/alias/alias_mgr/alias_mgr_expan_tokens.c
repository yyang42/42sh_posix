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
#include "twl_logger.h"
#include "data_utils.h"
#include "token/token_mgr.h"
#include "token/tokenizer.h"

static bool			find_fn(void *processed_item, void *found)
{
	return (alias_utils_starts_with(found, processed_item));
}

static char			*expan_token(t_token *token, char **accumulator_ptr,
														t_alias_processor *p)
{
	char			*found;

	found = twl_htab_get(p->aliases, token->text);
	if (found)
	{
		if (twl_lst_find(p->processed, find_fn, found))
			return (NULL);
		twl_lst_push_back(p->processed, token->text);
		*accumulator_ptr = twl_strjoinfree(*accumulator_ptr, found, 'l');
		return (found);
	}
	return (NULL);
}

static void			extend_tokens(t_alias_processor *p, char **accumulator)
{
	t_lst			*tokenized_tokens;
	t_tokenizer		*tokenizer;

	if (twl_lst_len(p->tokens))
	{
		*accumulator = twl_strjoinfree(*accumulator, "  ", 'l');
		*accumulator = twl_strjoinfree(*accumulator,
				token_mgr_first(p->tokens)->text, 'l');
		twl_lst_pop_front(p->tokens);
	}
	tokenizer = tokenizer_new(*accumulator);
	tokenizer->cur_line = p->line;
	tokenized_tokens = tokenizer_tokenize(tokenizer);
	token_mgr_mark_is_alias_expan(tokenized_tokens, p->processed);
	token_mgr_mark_is_alias_expan(tokenized_tokens, p->prev_processed);
	twl_lst_extend_front(p->tokens, tokenized_tokens);
	if (p->ast)
	{
		twl_lst_extend(p->ast->tokens_ref_tracker, tokenized_tokens);
	}
	tokenizer_del(tokenizer);
	twl_lst_del(tokenized_tokens, NULL);
}

bool				alias_mgr_expan_tokens_inner(t_alias_processor *p)
{
	t_token			*token;
	char			*alias;
	bool			has_expan;

	has_expan = false;
	while ((token = twl_lst_pop_front(p->copy_tokens)) &&
			!(data_utils_is_control_operators_nl(token->text)
				|| (data_utils_is_reserved_word(token->text)
					&& *p->accumulator == 0)))
	{
		alias = expan_token(token, &(p->accumulator), p);
		if (alias)
		{
			has_expan = true;
			if (twl_lst_find(p->prev_processed, find_fn, token->text))
				return (NULL);
			twl_lst_pop_front(p->tokens);
			if (twl_str_ends_with(alias, " ") && twl_lst_first(p->copy_tokens))
				continue ;
		}
		break ;
	}
	extend_tokens(p, &(p->accumulator));
	return (has_expan);
}

void				alias_mgr_expan_tokens(t_htab *aliases, t_lst *tokens,
		t_ast *ast)
{
	t_alias_processor	p;
	t_lst				*processed;

	if (twl_lst_len(tokens) == 0)
		return ;
	processed = twl_lst_new();
	p.line = token_mgr_first(tokens)->line;
	p.tokens = tokens;
	p.aliases = aliases;
	p.ast = ast;
	p.processed = processed;
	p.prev_processed = token_mgr_first(tokens)->source_alias_expans;
	p.accumulator = twl_strnew(0);
	p.copy_tokens = twl_lst_copy(p.tokens, NULL);
	while (alias_mgr_expan_tokens_inner(&p))
	{
		free(p.accumulator);
		twl_lst_del(p.copy_tokens, NULL);
		p.accumulator = twl_strnew(0);
		p.copy_tokens = twl_lst_copy(p.tokens, NULL);
	}
	free(p.accumulator);
	twl_lst_del(p.copy_tokens, NULL);
	twl_lst_del(processed, NULL);
}
