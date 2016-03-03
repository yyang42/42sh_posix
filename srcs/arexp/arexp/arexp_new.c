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

t_arexp				*arexp_new(char *input)
{
	t_arexp			*arexp;

	arexp = twl_malloc_x0(sizeof(t_arexp));
	arexp_singleton(arexp, false);
	arexp->tokens = tokenizer_arexp_tokenize(input);
<<<<<<< HEAD
	if (!twl_lst_len(arexp->tokens))
	{
		arexp->empty = true;
		return (arexp);
	}
	arexp->empty = false;
=======
>>>>>>> f5777dc6b95d80633fe7bb84aecaaacfc2cdca45
	arexp->expression = arexp_expression_new_from_tokens(arexp->tokens);
	if (token_mgr_first(arexp->tokens) && !arexp->error_msg)
	{
		arexp_set_error_msg(arexp, "unexpected token: ",
												token_mgr_first(arexp->tokens));
	}
	twl_lst_del(arexp->tokens, token_del);
	arexp->tokens = NULL;
	return (arexp);
}
