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

#include "data.h"
#include "token/tokenizer.h"

static bool			can_form_operator_with_fn(void *op, void *candidate)
{
	return (twl_strncmp(candidate, op, twl_strlen(candidate)) == 0);
}

bool				tokenizer_utils_can_form_operator(t_tokenizer *t,
															char *candidate)
{
	if (*candidate == '\0')
		return (false);
	return (twl_lst_find(
		data_all_operators(), can_form_operator_with_fn, candidate));
	(void)t;
}
