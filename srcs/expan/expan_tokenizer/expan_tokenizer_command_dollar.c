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

#include "expan/expan_tokenizer.h"
#include "expan/expan_exec.h"
#include "expan/expan_command.h"
#include "expan/expan_utils.h"
#include "expan/expan_token_origin.h"

static int		expan_token_parse_command_dollar(t_expan_command *command, char *str, int i)
{
	int	len;

	len = expan_tokenizer_get_word_len(&command->command, &str[i], "(");
	return (len + i + 1);
}

int				expan_tokenizer_command_dollar(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i)
	{
	t_expan_token	*expan_token;
	t_expan_command	*expan_command;

	expan_token = expan_token_new(COMMAND_SUBSTITUTION_DOLLAR, tokenizer->token);
	expan_command = expan_command_new();
	expan_token->origin = tokenizer->origin;
	i += 2;
	i = expan_token_parse_command_dollar(expan_command, str, i);
	expan_token->exec_expan = expan_exec_command;
	expan_token->expan_data = expan_command;
	expan_token->free_expan = expan_command_del;
	expan_token_mgr_add(expan_tokens, expan_token);
	return (i);
}