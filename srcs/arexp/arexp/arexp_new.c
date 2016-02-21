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

t_arexp				*arexp_new(char *input)
{
	t_arexp			*arexp;
//	t_lst			*tokens;

	arexp = twl_malloc_x0(sizeof(t_arexp));
	arexp->tokens = tokenizer_arexp_tokenize(input);
	//arexp->arexp_expression = arexp_expression_new_from_tokens(arexp->tokens);
	return (arexp);
}
