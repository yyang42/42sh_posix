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

static bool			can_form_operator_with(char *candidate, char *op)
{
	return (twl_strncmp(candidate, op, twl_strlen(candidate)) == 0);
}

bool				tokenizer_utils_can_form_operator(t_tokenizer *t,
															char *candidate)
{
	return (can_form_operator_with(candidate, "&&")
		|| can_form_operator_with(candidate, "||")
		|| can_form_operator_with(candidate, "<<-"));
	(void)t;
}

	// TOKEN_AND_IF "&&"
	// TOKEN_OR_IF "||"
	// TOKEN_DSEMI ";;"
	// TOKEN_DLESS "<<"
	// TOKEN_DGREAT ">>"
	// TOKEN_LESSAND "<&"
	// TOKEN_GREATAND ">&"
	// TOKEN_LESSGREAT "<>"
	// TOKEN_DLESSDASH "<<-"
	// TOKEN_CLOBBER ">|"
