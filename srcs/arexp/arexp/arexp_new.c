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

#include "token/tokenizer.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

#include <stdio.h>
static void pr(void *d){t_token *t=d;printf("%i - %s\n",t->type,t->text);}

t_arexp				*arexp_new(char *input)
{
	t_arexp			*arexp;

	arexp = twl_malloc_x0(sizeof(t_arexp));
	arexp->tokens = tokenizer_arexp_tokenize(input);
twl_lst_iter0(arexp->tokens, pr);
	arexp->expression = arexp_expression_new_from_tokens(arexp->tokens, arexp);
	if (token_mgr_first(arexp->tokens) && !arexp->error_msg)
	{
		arexp_set_error_msg(arexp, "unexpected token: ",
												token_mgr_first(arexp->tokens));
	}
	twl_lst_del(arexp->tokens, token_del);
	arexp->tokens = NULL;
	return (arexp);
}
