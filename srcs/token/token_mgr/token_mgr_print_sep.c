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

static void			print_token_fn(void *token_, void *next, void *sep)
{
	t_token	*token;

	token = token_;
	twl_putstr(token->text);
	if (next)
		twl_putstr(sep);
}

void				token_mgr_print_sep(t_lst *tokens, char *sep)
{
	twl_lst_itern(tokens, print_token_fn, sep);
}
