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

#include "token/token_list_mgr.h"
#include "token/token_mgr.h"
#include "ast/nodes/ast_list_item.h"
#include "ast/ast_lap.h"
#include "ast/ast.h"
#include "data.h"
#include "prog.h"

static void			ast_list_item_exec_check_error(t_ast_list_item *this, struct s_ast *ast)
{
	t_tokenizer		*tokenizer;
	char			*cmd;
	t_lst			*tokens;

	cmd = token_mgr_strjoin(this->list_item_tokens_deep, " ");
	tokenizer = tokenizer_new(cmd);
	tokens = tokenizer_tokenize(tokenizer);
	if (tokenizer->err_msg)
		ast->error_msg = twl_strdup(tokenizer->err_msg);
	tokenizer_del(tokenizer);
	token_mgr_del(tokens);
	free(cmd);
}

static bool			should_exec(struct s_ast *ast)
{
	return (shenv_singleton()->shenv_list_item_level == 1
			&& !(ast->ast_flags & AST_FLAG_NO_EXEC));
}

static void			ast_list_item_exec_wrapper(t_ast_list_item *this, struct s_ast *ast)
{
	ast_list_item_exec_check_error(this, ast);
	if (ast->error_msg)
		return ;
	if (should_exec(ast))
	{
		ast_list_item_exec(this);
	}
}

t_ast_list_item		*ast_list_item_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_list_item				*this;
	t_lst						*tmp_tokens;

	shenv_singleton()->shenv_list_item_level++;
	tmp_tokens = twl_lst_copy(tokens, NULL);
	this = ast_list_item_new();
	this->ast_andor_items = ast_lap_build_items(tokens, AST_TYPE_ANDOR_ITEM, ast);
	if (!ast->error_msg)
	{
		this->list_item_tokens_deep = twl_lst_copy_until(tmp_tokens, token_copy_void, twl_lst_first(tokens));
		if (twl_lst_first(tokens) && ast_list_item_is_delimiter(twl_lst_first(tokens)))
				twl_lst_push_back(this->list_item_tokens_deep, token_copy(twl_lst_first(tokens)));
		ast_list_item_exec_wrapper(this, ast);
	}
	shenv_singleton()->shenv_list_item_level--;
	twl_lst_del(tmp_tokens, NULL);
	return (this);
}
