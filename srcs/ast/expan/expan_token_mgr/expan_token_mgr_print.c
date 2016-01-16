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

#include "ast/expan/ast_expan_token.h"

static void			iter_fn(void *expan_token_)
{
	t_expan_token *expan_token;

	expan_token = expan_token_;
	expan_token_print(expan_token);
}

void				expan_token_mgr_print(t_lst *tokens)
{
	twl_lst_iter0(tokens, iter_fn);
}
