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

#include "ast/ast.h"

#include "twl_arr.h"
#include "utils.h"
#include "token_mgr.h"

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
		if (twl_strequ(token->text, ";"))
			break;
		twl_lst_push(list->tokens, twl_lst_shift(tokens));
	}
}

t_ast_list *ast_build_list(t_ast *ast, t_lst *tokens)
{
	t_ast_list		*list;
	t_ast_list		*left_list;
	t_token			*token;

	left_list = NULL;
	list = ast_list_new();
	build_tokens(list, tokens);
	token = twl_lst_first(tokens);
	if (token && twl_strequ(token->text, ";"))
	{
		twl_lst_shift(tokens);
		left_list = ast_build_list(ast, tokens);
	}
	if (left_list)
	{
		push_to_last(left_list, list);
		list = left_list;
	}
	return (list);
	(void)ast;
}
