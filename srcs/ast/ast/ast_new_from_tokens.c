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

t_ast				*ast_new_from_tokens_do(t_lst *src_tokens)
{
	t_ast			*ast;
	t_lst			*tokens_copy;

	ast = twl_malloc_x0(sizeof(t_ast));
	ast->tokens_ref_tracker = twl_lst_copy(src_tokens, token_copy_void);
	tokens_copy = twl_lst_copy(ast->tokens_ref_tracker, NULL);
	ast->compound_list = ast_compound_list_new_from_tokens(tokens_copy, ast);
	if ((twl_lst_len(tokens_copy) > 0)
		&& !ast->error_msg)
		ast_set_error_msg_syntax_error_near(ast, twl_lst_first(tokens_copy), NULL);
	token_mgr_del_shallow(tokens_copy);
	return (ast);
}

t_ast				*ast_new_from_tokens(t_lst *src_tokens)
{
	int				saved_level;
	t_ast			*ast;

	saved_level = shenv_singleton()->shenv_list_item_level;
	shenv_singleton()->shenv_list_item_level = 0; // REFACTOR NOT RELIABLE
	ast = ast_new_from_tokens_do(src_tokens);
	shenv_singleton()->shenv_list_item_level = saved_level; // REFACTOR NOT RELIABLE
	return (ast);
}
