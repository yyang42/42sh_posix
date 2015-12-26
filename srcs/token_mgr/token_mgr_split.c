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

#include "token_mgr.h"

static bool			find_fn(void *str, void *needle)
{
	return (twl_strequ(str, needle));
}

static void			do_split(t_lst *tokens, t_lst *tokens_list, t_lst **token_tmp_ptr, t_lst *split_strings)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;

	elem = tokens->head;
	while (elem)
	{
		next = elem->next;
		twl_lst_push(*token_tmp_ptr, elem->data);
		if (twl_lst_find(split_strings, find_fn, ((t_token *)elem->data)->text))
		{
			*token_tmp_ptr = twl_lst_new();
			twl_lst_push(tokens_list, *token_tmp_ptr);
		}
		elem = next;
	}
	(void)split_strings;
}

t_lst				*token_mgr_split(t_lst *tokens, t_lst *split_strings)
{
	t_lst			*tokens_list;
	t_lst			*tokens_tmp;

	tokens_list = twl_lst_new();
	tokens_tmp = twl_lst_new();
	twl_lst_push(tokens_list, tokens_tmp);
	do_split(tokens, tokens_list, &tokens_tmp, split_strings);
	(void)split_strings;
	(void)tokens;
	return (tokens_list);
}
