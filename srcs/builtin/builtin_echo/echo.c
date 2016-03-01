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

#include "builtin/builtin_echo.h"

static void iter_fn(void *token_, void *next, void *ctx)
{
	t_token			*token;

	token = token_;
	twl_putstr(token->text);
	if (next)
		twl_putstr(" ");
	(void)ctx;
}

int				builtin_echo(t_lst *tokens, t_environment *this)
{
	t_lst			*copy;
	bool			opt_n;

	opt_n = false;
	copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(copy);
	if (token_mgr_first_equ(copy, "-n"))
	{
		opt_n = true;
		twl_lst_pop_front(copy);
	}
	twl_lst_itern(copy, iter_fn, NULL);
	if (!opt_n)
		twl_putstr("\n");
	environment_set_last_exit_status_2(this, BUILTIN_EXEC_SUCCESS);
	twl_lst_del(copy, NULL);
	return (0);
}
