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

static void			print_token_fn(void *token_, void *segs)
{
	t_token	*token;

	token = token_;
	twl_lst_push(segs, token->text);
}

char				**token_mgr_to_str_arr(t_lst *tokens)
{
	t_lst			*segs;
	char			**arr;

	segs = twl_lst_new();
	twl_lst_iter(tokens, print_token_fn, segs);
	arr = (char **)twl_lst_to_arr(segs);
	twl_lst_del(segs, NULL);
	return (arr);
}
