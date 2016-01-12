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

t_ast				*ast_new(char *input)
{
	t_ast			*ast;
	t_lst			*tokens;

	ast = twl_malloc_x0(sizeof(t_ast));
	ast->tokens = tokenizer_tokenize(input);
	tokens = twl_lst_copy(ast->tokens, NULL);
	ast->compound_list = ast_compound_list_new_from_tokens_bis(ast->tokens, ast);
	token_mgr_del(tokens);
	return (ast);
}
