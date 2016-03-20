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

#include "ast/ast.h"

int					ast_exec_string(char *input)
{
	int				exit_code;
	t_lst			*tokens;
	t_tokenizer		*tokenizer;

	tokenizer = tokenizer_new(input);
	tokens = tokenizer_tokenize(tokenizer);
	if (tokenizer->err_msg)
	{
		twl_dprintf(2, "%s\n", tokenizer->err_msg);
		exit(2);
		exit_code = 1;
	}
	else
	{
		exit_code = ast_exec_tokens(tokens);
	}
	tokenizer_del(tokenizer);
	token_mgr_del_inner(tokens);
	return (exit_code);
}
