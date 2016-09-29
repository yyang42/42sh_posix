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

#include "builtin/cmds/builtin_echo.h"

static void			iter_fn(void *token_, void *next, void *ctx)
{
	t_token			*token;

	token = token_;
	twl_putstr(token->text);
	if (next)
		twl_putstr(" ");
	(void)ctx;
}

void				builtin_echo_exec(t_lst *tokens, t_shenv *this)
{
	t_lst			*tokens_copy;
	bool			print_newline;

	print_newline = true;
	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	if (token_mgr_first_equ(tokens_copy, "-n"))
	{
		print_newline = false;
		twl_lst_pop_front(tokens_copy);
	}
	twl_lst_itern(tokens_copy, iter_fn, NULL);
	if (print_newline)
	{
		twl_putstr("\n");
	}
	twl_lst_del(tokens_copy, NULL);
	(void)this;
}
