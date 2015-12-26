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

#include "twl_arr.h"
#include "utils.h"
#include "token_mgr.h"

#include "ast/nodes/ast_list.h"

static void			push_to_last(t_ast_list *head, t_ast_list *tail)
{
	t_ast_list *tmp;

	tmp = head;
	while (tmp->list)
		tmp = tmp->list;
	tmp->list = tail;
}

static void			build_tokens(t_ast_list *list, t_lst *tokens)
{
	t_token			*token;

	list->tokens = twl_lst_new();
	while ((token = twl_lst_first(tokens)))
	{
		if (ast_separator_op_is_own_type(tokens)
			|| twl_strequ(token->text, "\n"))
			break;
		twl_lst_push(list->tokens, twl_lst_shift(tokens));
	}
}

static bool			is_candidate(t_lst *tokens)
{
	t_token			*first;
	t_token			*second;

	first = twl_lst_first(tokens);
	second = twl_lst_get(tokens, 1);

	return (first && second
		&& ast_separator_op_is_own_type(tokens)
		&& !twl_strequ(second->text, "\n"));
}

t_ast_list			*ast_list_new_from_tokens(t_lst *tokens)
{
	t_ast_list		*list;
	t_ast_list		*left_list;
	// t_ast_separator_op *ast_separator_op;


	left_list = NULL;
	list = ast_list_new();
	build_tokens(list, tokens);
	if (is_candidate(tokens))
	{
		list->ast_separator_op = ast_separator_op_new_from_tokens(tokens);
		left_list = ast_list_new_from_tokens(tokens);
	}
	if (left_list)
	{
		push_to_last(left_list, list);
		list = left_list;
	}
	return (list);
}
