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
#include "ast/ast.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

static void			push_asign_fn(void *assignment_token_, void *assignment_items, void *ast)
{
	t_token			*assignment_token;
	t_lst			*segs;

	assignment_token = assignment_token_;
	segs = twl_str_split_to_lst(assignment_token->text, "=");
	twl_lst_push(assignment_items, ast_assignment_new_from_tokens(
		twl_lst_get(segs, 0), twl_lst_get(segs, 1), ast));
	twl_lst_del(segs, free);
}

static void			push_redir_fn(void *one_redir_tokens, void *redir_items, void *ast)
{
	t_ast_redir		*ast_redir;

	if (ast_has_error(ast))
		return ;
	ast_redir = ast_redir_new_from_tokens(one_redir_tokens, ast);
	if (ast_has_error(ast))
		return ;
	twl_lst_push(redir_items, ast_redir);
}

static void			build_tokens(t_ast_simple_command *this, t_lst *orig_tokens, struct s_ast *ast)
{
	t_lst			*redir_tokens_groups;
	t_lst			*assignment_tokens;
	t_lst			*remaining_of_redir_tokens;
	t_lst			*remaining_of_assign_tokens;

	remaining_of_redir_tokens = twl_lst_new();
	remaining_of_assign_tokens = twl_lst_new();
	redir_tokens_groups = token_mgr_extract_redir(orig_tokens, remaining_of_redir_tokens);
	assignment_tokens = token_mgr_extract_assignment(remaining_of_redir_tokens, remaining_of_assign_tokens);
	this->command_tokens = twl_lst_copy(remaining_of_assign_tokens, NULL);
	twl_lst_iter2(redir_tokens_groups, push_redir_fn, this->redir_items, ast);
	if (!ast_has_error(ast))
		twl_lst_iter2(assignment_tokens, push_asign_fn, this->assignment_items, ast);
	twl_lst_del(remaining_of_redir_tokens, NULL);
	twl_lst_del(remaining_of_assign_tokens, NULL);
	token_list_mgr_del(redir_tokens_groups);
	twl_lst_del(assignment_tokens, NULL);
}

t_ast_simple_command	*ast_simple_command_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_simple_command		*this;

	this = ast_simple_command_new();
	build_tokens(this, tokens, ast);
	if (ast_has_error(ast))
	{
		ast_simple_command_del(this);
		return (NULL);
	}
	return (this);
}
