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
	tokens = tokenizer_tokenize(input);
	ast->complete_command = ast_complete_command_new_from_tokens(tokens);
	// if (twl_lst_len(tokens) > 0)
	// {
	// 	twl_printf(C_RED "[ERROR] start\n" C_CLEAR);
	// 	token_mgr_print(tokens);
	// 	twl_printf("Expect tokens len to be 0, but found %zu\n", twl_lst_len(tokens));
	// 	twl_printf(C_RED "[ERROR] end\n" C_CLEAR);
	// }
	return (ast);
}
