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


#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

static void			push_asign_fn(void *assignment_token_, void *assignment_items)
{
	t_token			*assignment_token;
	t_lst			*segs;

	assignment_token = assignment_token_;
	segs = twl_str_split_to_lst(assignment_token->text, "=");
	twl_lst_push(assignment_items, ast_assignment_new_from_tokens(
		twl_lst_get(segs, 0), twl_lst_get(segs, 1)));
	twl_lst_del(segs, free);
	(void)assignment_items;
}

static void			push_redir_fn(void *one_redir_tokens, void *redir_items)
{
	twl_lst_push(redir_items, ast_redir_new_from_tokens(one_redir_tokens));
}

static void			build_tokens(t_ast_simple_command *this, t_lst *orig_tokens)
{
	t_lst			*redir_tokens_groups;
	t_lst			*assignment_tokens;
	t_lst			*tmp_tokens;

	tmp_tokens = twl_lst_copy(orig_tokens, NULL);
	redir_tokens_groups = token_mgr_extract_redir(tmp_tokens);
	assignment_tokens = token_mgr_extract_assignment(tmp_tokens);
	this->command_tokens = twl_lst_copy(tmp_tokens, NULL);
	twl_lst_iter(redir_tokens_groups, push_redir_fn, this->redir_items);
	twl_lst_iter(assignment_tokens, push_asign_fn, this->assignment_items);
	twl_lst_del(tmp_tokens, NULL);
}

t_ast_simple_command	*ast_simple_command_new_from_tokens(t_lst *tokens)
{
	t_ast_simple_command		*this;

	this = ast_simple_command_new();
	build_tokens(this, tokens);
	return (this);
}
