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

#include "ast/nodes/ast_simple_command.h"
#include "ast/expan/ast_expan_mgr.h"
#include "ast/expan/ast_expan_tokenizer.h"
#include "ast/expan/ast_expan_exec.h"

void	expan_init(char **ptr, t_token_origin origin)
{
	t_lst					*expan_tokens;
	char					*concat;

	expan_tokens = expan_token_mgr_new();
	expan_tokenizer(*ptr, expan_tokens, origin);
	expan_exec(expan_tokens);
	// expan_token_mgr_print(expan_tokens);
	concat = expan_tokenizer_concat(expan_tokens);
	if (concat)
	{
		twl_strdel(ptr);
		*ptr = concat;
	}
	expan_token_mgr_del(expan_tokens);
}
