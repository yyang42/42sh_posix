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

static void			push_to_ast_open_stack(void *elem, void *ast_open_stack)
{
	twl_lst_push_back(ast_open_stack, twl_strdup(elem));
}

t_ast				*ast_new_from_string(char *input, int ast_flags, int line)
{
	t_ast			*ast;
	t_lst			*tokens;
	t_tokenizer		*tokenizer;

	if (shenv_shflag_exist(shenv_singleton(), "verbose"))
		twl_putstr_fd(input, 2);
	tokenizer = tokenizer_new(input);
	tokenizer->cur_line = line;
	tokens = tokenizer_tokenize(tokenizer);
	ast = ast_new(tokens, ast_flags);
	twl_lst_iter(tokenizer->tok_open_stack,
		push_to_ast_open_stack, ast->ast_open_stack);
	tokenizer_del(tokenizer);
	token_mgr_del(tokens);
	return (ast);
}
