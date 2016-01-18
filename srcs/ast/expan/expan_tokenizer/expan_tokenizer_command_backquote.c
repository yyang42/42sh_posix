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

#include "ast/expan/ast_expan_tokenizer.h"
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_command.h"
#include "ast/expan/ast_expan_token_origin.h"

static int		expan_token_parse_command_backquote(t_expan_command *command, char *str, int i)
{
	bool	is_between_sq;
	bool	is_between_dq;
	int		j;

	is_between_dq = false;
	is_between_sq = false;
	j = i;
	while (str[j] != 0)
	{
			if (str[j] == '\'')
				is_between_sq = !is_between_sq;
			else if (str[j] == '"')
				is_between_dq = !is_between_dq;
			else if (str[j] == '`' && !is_between_dq && !is_between_sq)
				break;
	}
	if (i < j)
		command->command = twl_strndup(&str[i], j - i);
	return (j);
}

int				expan_tokenizer_command_backquote(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i)
	{
	t_expan_token	*expan_token;
	t_expan_command	*expan_command;

	expan_token = expan_token_new(COMMAND_SUBSTITUTION_BACKQUOTE);
	expan_command = expan_command_new();
	expan_token->origin = tokenizer->origin;
	i += 2;
	i = expan_token_parse_command_backquote(expan_command, str, i);
	expan_token->exec_expan = expan_exec_command;
	expan_token->expan_data = expan_command;
	expan_token_mgr_add(expan_tokens, expan_token);
	return (i);
}
