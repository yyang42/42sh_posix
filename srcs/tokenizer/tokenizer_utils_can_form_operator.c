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

#include "tokenizer.h"

#define MAX_OPERATOR_NUMBER 9
static char			operators[MAX_OPERATOR_NUMBER][3] = {"<<-",
							"&&", "||", ";;", "<<", "<&", ">&", "<>", ">|"};

static bool			can_form_operator_with(char *candidate, char *op)
{
	return (twl_strncmp(candidate, op, twl_strlen(candidate)) == 0);
}

bool				tokenizer_utils_can_form_operator(t_tokenizer *t,
															char *candidate)
{
	int 			i;

	if (*candidate == '\0')
		return (false);
	i = 0;
	while (i < MAX_OPERATOR_NUMBER)
	{
		if (can_form_operator_with(candidate, operators[i]))
			return (true);
		i++;
	}
	return (false);
	(void)t;
}
