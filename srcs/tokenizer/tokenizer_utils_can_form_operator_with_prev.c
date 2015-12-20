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
	char			*operator;
	char			*token;

	token = twl_strndup(this->input + this->i - this->ti, this->ti + 1);
	operator = this->input + this->i - 1;
	return (twl_strncmp(token, str, twl_strlen(token)) == 0);
}

bool				tokenizer_utils_can_form_operator_with_prev(
														t_tokenizer *this)
{
	return (can_form_operator_with(this, "&&"));
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
