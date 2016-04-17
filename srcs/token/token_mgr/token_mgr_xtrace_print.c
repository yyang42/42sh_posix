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

static void			print_token_fn(void *token_, void *next, void *ctx)
{
	t_token	*token;

	token = token_;
	twl_putstr_fd(token->text, 2);
	if (next)
		twl_putstr_fd(" ", 2);
	(void)ctx;
}

void				token_mgr_xtrace_print(t_lst *tokens)
{
	twl_putstr_fd("+ ", 2);
	twl_lst_itern(tokens, print_token_fn, NULL);
	twl_putstr_fd("\n", 2);
}
