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
#include "ast/expan/ast_expan_tilde.h"
#include "ast/expan/ast_expan_token_origin.h"

static int		expan_tokenizer_tilde_parse(char *str, int i,
	t_token_origin origin)
{
	int j;
	bool is_double_quoted;
	is_double_quoted = false;

	j = i;
	while (str[j] != 0)
	{
		if (str[j] == '\"')
			is_double_quoted = !is_double_quoted;
		if (str[j] == '/' && !is_double_quoted)
			break;
		if (origin == ASSIGNMENT_VALUE && str[j] == ':' && !is_double_quoted)
			break;
		j++;
	}
	return (j);
}

int				expan_tokenizer_tilde(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i){
	t_expan_token	*expan_token;
	t_expan_tilde	*expan_tilde;
	int j;

	expan_token = expan_token_new(TILDE);
	expan_tilde = expan_tilde_new();
	expan_tilde->token = twl_strndup(str, 1);
	i++;
	j = expan_tokenizer_tilde_parse(str, i, expan_token->origin);
	if (j > i)
		expan_tilde->suffix = twl_strndup(&str[i], j - i);
	expan_token->origin = tokenizer->origin;
	expan_token->exec_expan = expan_exec_tilde;
	expan_token->expan_data = expan_tilde;
	expan_token_mgr_add(expan_tokens, expan_token);
	return (j);
}
