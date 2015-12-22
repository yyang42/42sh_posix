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

static bool			can_form_operator_with(t_tokenizer *this, char *str)
{
	char			*token;
	bool			can_form_op;

	token = twl_strnew(twl_strlen(this->curtoken) + 1);
	twl_strcpy(token, this->curtoken);
	token[twl_strlen(token)] = *(this->curpos);
	can_form_op = (twl_strncmp(token, str, twl_strlen(token)) == 0);
	free(token);
	return (can_form_op);
}

bool				tokenizer_utils_can_form_operator_with_prev(
														t_tokenizer *this)
{
	return (can_form_operator_with(this, "&&")
		|| can_form_operator_with(this, "||")
		|| can_form_operator_with(this, "<<-"));
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
