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

static void			print_token_fn(void *token_)
{
	t_token	*token;

	token = token_;
	twl_printf("<%s>\n", token->text);
}

void				token_mgr_print(t_lst *tokens)
{
	twl_printf("%s>>>>>>>>>> token list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(tokens, print_token_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
