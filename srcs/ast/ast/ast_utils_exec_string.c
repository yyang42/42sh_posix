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

void				ast_utils_exec_string(char *input)
{
	t_lst			*tokens;
	t_tokenizer		*tokenizer;

	tokenizer = tokenizer_new(input);
	tokens = tokenizer_tokenize(tokenizer);
	ast_utils_exec_tokens(tokens);
	tokenizer_del(tokenizer);
	token_mgr_del(tokens);
}
