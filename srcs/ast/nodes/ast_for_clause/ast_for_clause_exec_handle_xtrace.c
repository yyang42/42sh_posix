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

#include "ast/nodes/ast_if_then.h"
#include "ast/nodes/ast_for_clause.h"

static void			print_token_fn(void *token_, void *next, void *ctx)
{
	t_token	*token;

	token = token_;
	twl_putstr_fd(token->text, 2);
	if (next)
	{
		twl_putstr_fd(" ", 2);
	}
	(void)ctx;
}

void				ast_for_clause_exec_handle_xtrace(t_ast_for_clause *this)
{
	;
	if (shenv_flag_exist(shenv_singleton(), "xtrace"))
	{
		twl_dprintf(2, "+ for %s in ", this->name);
		twl_lst_itern(this->wordlist, print_token_fn, NULL);
		twl_putstr_fd("\n", 2);
	}
}
