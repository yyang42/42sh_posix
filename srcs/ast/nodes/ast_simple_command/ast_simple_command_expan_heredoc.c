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

#include "ast/nodes/ast_simple_command.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "expan/expansion.h"
#include "shenv/shenv.h"
#include "token/token_mgr.h"
#include "pattern_matching/pattern.h"
#include "pattern_matching/brace/brace.h"

static t_expansion	*ast_simple_command_expan_heredoc_init(t_ast_redir *redir)
{
	t_expansion	*expansion;
	t_pattern	*pattern_test;
	char		*pattern_unquoted;

	pattern_test = pattern_new(redir->param->text_unexpanded);
	pattern_unquoted = pattern_to_string(pattern_test);
	pattern_del(pattern_test);
	if (twl_strcmp(pattern_unquoted, redir->param->text))
	{
		free(pattern_unquoted);
		return (NULL);
	}
	free(pattern_unquoted);
	if (redir->heredoc_text)
		free(redir->heredoc_text);
	expansion = expansion_new_from_text_remove_squote(
			redir->heredoc_text_unexpanded);
	return (expansion);
}

void				ast_simple_command_expan_heredoc(t_ast_redir *redir)
{
	t_expansion	*expansion;

	if (!(expansion = ast_simple_command_expan_heredoc_init(redir)))
		return ;
	redir->heredoc_text = expansion_get_string_heredoc(expansion);
	if (expansion->error)
	{
		shenv_singl_error(0, "%s", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	expansion_del(expansion);
}
