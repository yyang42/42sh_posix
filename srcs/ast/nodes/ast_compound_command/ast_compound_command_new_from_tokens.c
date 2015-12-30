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

#include "openclose_matcher.h"
#include "ast/nodes/ast_compound_command.h"
#include "ast/nodes/ast_redir.h"

static void			push_redir_fn(void *one_redir_tokens, void *redir_items)
{
	twl_lst_push(redir_items, ast_redir_new_from_tokens(one_redir_tokens));
}

static void			build_redir_tokens(t_lst *redir_items, t_lst *orig_redir_tokens)
{
	t_lst			*redir_tokens_groups;
	t_lst			*redir_tokens;

	redir_tokens = twl_lst_copy(orig_redir_tokens, NULL);
	redir_tokens_groups = token_mgr_extract_redir(redir_tokens);
	twl_lst_iter(redir_tokens_groups, push_redir_fn, redir_items);
	twl_lst_del(redir_tokens, NULL);
}

static void			new_compound_command_do(t_ast_compound_command *this, t_lst *tokens)
{
	int						pos;
	t_openclose_matcher		*matcher;
	t_lst					*redir_tokens;

	matcher = openclose_matcher_singleton_parser();
	pos = openclose_matcher_token_find_matching(matcher, tokens);
	this->command_tokens = twl_lst_slice(tokens, 0, pos);
	redir_tokens = twl_lst_slice(tokens, pos, twl_lst_len(tokens));
	this->command = compound_command_from_token_fns()[this->command_type](this->command_tokens);
	build_redir_tokens(this->redir_items, redir_tokens);
	twl_lst_del(redir_tokens, NULL);
}

t_ast_compound_command	*ast_compound_command_new_from_tokens(t_lst *tokens)
{
	t_ast_compound_command		*this;

	this = ast_compound_command_new();
	this->command_type = compound_command_get_type_from_tokens(tokens);
	if (this->command_type != COMPOUND_COMMAND_NONE)
	{
		new_compound_command_do(this, tokens);
	}
	return (this);
}
