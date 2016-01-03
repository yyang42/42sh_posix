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

char				*token_mgr_strjoin(t_lst *tokens, char *sep)
{
	t_lst			*segs;

	segs = twl_lst_new();
	twl_lst_iter(tokens, print_token_fn, segs);
	return (twl_lst_strjoin(segs, sep));
}
