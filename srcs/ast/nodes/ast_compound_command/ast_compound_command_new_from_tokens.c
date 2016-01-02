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

#include "openclose/openclose_matcher.h"
#include "ast/nodes/ast_compound_command.h"
#include "ast/nodes/ast_redir.h"
#include "ast/ast.h"

static void			push_redir_fn(void *one_redir_tokens, void *redir_items, void *ast)
{
	twl_lst_push(redir_items, ast_redir_new_from_tokens(one_redir_tokens, ast));
}

static void			build_redir_tokens(t_lst *redir_items, t_lst *orig_redir_tokens, struct s_ast *ast)
{
	t_lst			*redir_tokens_groups;
	t_lst			*redir_tokens;

	redir_tokens = twl_lst_copy(orig_redir_tokens, NULL);
	redir_tokens_groups = token_mgr_extract_redir(redir_tokens);
	twl_lst_iter2(redir_tokens_groups, push_redir_fn, redir_items, ast);
	twl_lst_del(redir_tokens, NULL);
}

static int			new_compound_command_do(t_ast_compound_command *this, t_lst *tokens, struct s_ast *ast)
{
	int						pos;
	t_openclose_matcher		*matcher;
	t_lst					*redir_tokens;

	matcher = openclose_matcher_singleton_parser();
	pos = openclose_matcher_token_find_matching(matcher, tokens);
	if (pos == -1)
	{
		ast_set_error_msg_format(ast, token_mgr_first(tokens),
				"Closing token for '%s' not found", token_mgr_first(tokens)->text);
		return (-1);
	}
	this->command_tokens = twl_lst_slice(tokens, 0, pos);
	// token_mgr_print(this->command_tokens);
	redir_tokens = twl_lst_slice(tokens, pos, twl_lst_len(tokens));
	this->command = compound_command_from_token_fns()[this->command_type](this->command_tokens, ast);
	if (this->command == NULL)
		return (-1);
	build_redir_tokens(this->redir_items, redir_tokens, ast);
	twl_lst_del(redir_tokens, NULL);
	return (0);
}

t_ast_compound_command	*ast_compound_command_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_compound_command		*this;

	this = ast_compound_command_new();
	this->command_type = compound_command_get_type_from_tokens(tokens);
	if (this->command_type != COMPOUND_COMMAND_NONE)
	{
		if (new_compound_command_do(this, tokens, ast) == -1)
			return (NULL);
	}
	return (this);
}
