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

#include "ast/nodes/ast_assignment.h"
#include "data.h"
#include "openclose/openclose_matcher.h"
#include "token/token_mgr.h"
#include "token/token_utils.h"
#include "utils.h"
#include "twl_ctype.h"

static bool				is_valid_assignment_token(t_token *token)
{
	char				*str;

	str = token->text;
	if (!str || twl_isdigit(*str) || *str == '\0' || *str == '=')
		return (false);
	while (*str && *str != '=')
	{
		if (!twl_isalpha(*str) && !twl_isdigit(*str) && *str != '_')
			return (false);
		str += 1;
	}
	return (*str == '=');
}

static t_ast_assignment	*build_assign(t_token *token)
{
	t_lst				*segs;
	t_ast_assignment	*assign;

	segs = twl_str_split_once_to_lst(token->text, "=");
	assign = ast_assignment_new(token, twl_lst_get(segs, 0),
		twl_lst_get(segs, 1));
	twl_lst_del(segs, free);
	return (assign);
}

static void				do_extract(t_lst *tokens, t_lst *assign_list,
													t_lst *remaining_tokens)
{
	t_token			*token;

	while ((token = twl_lst_first(tokens)))
	{
		if (is_valid_assignment_token(token))
		{
			twl_lst_push_back(assign_list,
					build_assign(twl_lst_pop_front(tokens)));
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

t_lst					*token_mgr_extract_assignment(t_lst *tokens,
														t_lst *remaining_tokens)
{
	t_lst			*assign_list;
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	assign_list = twl_lst_new();
	do_extract(tokens_copy, assign_list, remaining_tokens);
	twl_lst_del(tokens_copy, NULL);
	return (assign_list);
}
