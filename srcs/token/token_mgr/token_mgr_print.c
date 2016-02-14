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

static void			print_token_fn(void *token_)
{
	t_token	*token;

	token = token_;
	COUCOU;
	twl_lprintf("<%s>\n", token->text);
	COUCOU;
}

void				token_mgr_print(t_lst *tokens)
{
	twl_lprintf("%s>>>>>>>>>> token list (%zu) %s\n", C_CYAN,
												twl_lst_len(tokens), C_CLEAR);
	COUCOU;
	twl_lst_iter0(tokens, print_token_fn);
	COUCOU;
	twl_lprintf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
