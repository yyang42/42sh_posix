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

void					expan_tokenizer(t_ast_simple_command *cmd,
	t_token *token, t_lst *expan_tokens)
{
	int i;
	int	last;

	i = 0;
	last = 0;
	if (token->text)
	{
		while (token->text[i] != 0)
		{
			if (token->text[i] == '$')
			{
				expan_tokenizer_none(expan_tokens, &token->text[last], i - last);
			}
			i++;
		}
	}
	(void)token;
	(void)expan_tokens;
	(void)cmd;
}
