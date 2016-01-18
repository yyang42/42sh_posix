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

#include "utils.h"
#include "data.h"
#include "token/token_utils.h"
#include "token/token_mgr.h"
#include "openclose/openclose_matcher.h"

static bool			is_assignment(char *str)
{
	t_lst			*segs;
	bool			is_assign;

	segs = twl_str_split_to_lst(str, "=");
	if (*str && str[twl_strlen(str) - 1] == '=')
		return (true);
	if (twl_lst_len(segs) >= 2
		&& token_utils_is_valid_name(twl_lst_first(segs)))
		is_assign = true;
	else
		is_assign = false;
	twl_lst_del(segs, free);
	return (is_assign);
}

static void			do_extract(t_lst *tokens, t_lst *assign_tokens, t_lst *remaining_tokens)
{
	t_token			*token;

	while ((token = twl_lst_first(tokens)))
	{
		if (is_assignment(token->text))
		{
			twl_lst_push_back(assign_tokens, twl_lst_pop_front(tokens));
		}
		else
		{
			break ;
		}
	}
	while ((token = twl_lst_first(tokens)))
	{
		twl_lst_push_back(remaining_tokens, twl_lst_pop_front(tokens));
	}
}

t_lst				*token_mgr_extract_assignment(t_lst *tokens, t_lst *remaining_tokens)
{
	t_lst			*assign_tokens;
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	assign_tokens = twl_lst_new();
	do_extract(tokens_copy, assign_tokens, remaining_tokens);
	twl_lst_del(tokens_copy, NULL);
	return (assign_tokens);
}
