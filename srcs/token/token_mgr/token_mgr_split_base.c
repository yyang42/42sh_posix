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
#include "openclose/openclose_matcher.h"

static void			hande_openclose(t_openclose_matcher *matcher,
								t_lst *tokens, t_lst *tokens_tmp)
{
	int				pos;

	pos = openclose_matcher_token_find_matching(matcher, tokens);
	if (pos == -1)
		pos = twl_lst_len(tokens);
	while (pos > 0)
	{
		twl_lst_push(tokens_tmp, twl_lst_shift(tokens));
		pos--;
	}
}

static void			do_split_true(t_lst *tokens, t_lst *tokens_list,
									t_lst *split_strings,
									t_openclose_matcher *matcher)
{
	t_token					*token;
	t_lst					*tokens_tmp;

	tokens_tmp = twl_lst_new();
	twl_lst_push(tokens_list, tokens_tmp);
	while ((token = twl_lst_first(tokens)))
	{
		if (openclose_matcher_is_open(matcher, token->text))
		{
			hande_openclose(matcher, tokens, tokens_tmp);
		}
		else if (twl_lst_find(split_strings, twl_strequ_void, token->text))
		{
			twl_lst_push(tokens_tmp, twl_lst_shift(tokens));
			tokens_tmp = twl_lst_new();
			twl_lst_push(tokens_list, tokens_tmp);
		}
		else
		{
			twl_lst_push(tokens_tmp, twl_lst_shift(tokens));
		}
	}
}

static void			do_split_false(t_lst *tokens, t_lst *tokens_list,
									t_lst *split_strings,
									t_openclose_matcher *matcher)
{
	t_token					*token;
	t_lst					*tokens_tmp;

	tokens_tmp = twl_lst_new();
	twl_lst_push(tokens_list, tokens_tmp);
	while ((token = twl_lst_first(tokens)))
	{
		if (openclose_matcher_is_open(matcher, token->text))
		{
			hande_openclose(matcher, tokens, tokens_tmp);
		}
		else if (twl_lst_find(split_strings, twl_strequ_void, token->text))
		{
			twl_lst_shift(tokens);
			tokens_tmp = twl_lst_new();
			twl_lst_push(tokens_list, tokens_tmp);
		}
		else
		{
			twl_lst_push(tokens_tmp, twl_lst_shift(tokens));
		}
	}
}

t_lst				*token_mgr_split_base(t_lst *tokens, t_lst *split_strings,
												t_openclose_matcher *matcher,
														bool keep_delimiter)
{
	t_lst			*tokens_list;
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	tokens_list = twl_lst_new();
	if (keep_delimiter)
		do_split_true(tokens_copy, tokens_list, split_strings, matcher);
	else
		do_split_false(tokens_copy, tokens_list, split_strings, matcher);
	token_mgr_del(tokens_copy);
	return (tokens_list);
}
