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

t_ast				*ast_new_from_string(char *input, int flags)
{
	t_ast			*ast;
	t_lst			*tokens;

	if (shenv_shflag_exist(shenv_singleton(), "verbose"))
		twl_putstr_fd(input, 2);
	tokens = tokenizer_utils_tokenize(input);
	ast = ast_new(tokens, flags);
	token_mgr_del(tokens);
	return (ast);
}
