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

#include "ast/ast_lap.h"
#include "alias/alias_mgr.h"

static bool		is_last_sep_that_require_more_tokens(t_token *token)
{
	return (token
		&& (twl_strequ(token->text, "&&")
			|| twl_strequ(token->text, "||")
			|| twl_strequ(token->text, "|")));
}

static bool		is_type_separator(t_ast_type type, t_token *token)
{
	return (token
		&& twl_lst_find(ast_lap_get_seps_list()[type],
			twl_strequ_void, token->text));
}

static bool		should_break_fn(t_lst *tokens, t_ast_type type,
		t_token *last_sep)
{
	if (!twl_lst_first(tokens))
		return (true);
	if (token_mgr_first_equ(tokens, ";;") ||
		data_utils_is_reserved_word_middle_end(token_mgr_first(tokens)->text))
		return (true);
	if (type == AST_TYPE_LIST_ITEM &&
			last_sep && token_mgr_first_equ(tokens, ")"))
		return (true);
	return (false);
}

static t_lst	*ast_lap_build_items_end_fn(t_lst *tokens, t_ast_type type,
				struct s_ast *ast, t_ast_lap *l)
{
	if (token_mgr_first_equ(tokens, "("))
	{
		ast_set_error_msg_syntax_error_near(ast, token_mgr_first(tokens), NULL);
		twl_lst_del(l->container, ast_lap_del_fns()[type]);
		return (NULL);
	}
	if (is_last_sep_that_require_more_tokens(l->last_sep))
	{
		ast_add_to_open_stack(ast, l->last_sep->text);
		ast_set_error_msg_syntax_error_near(ast, l->last_sep, NULL);
		twl_lst_del(l->container, ast_lap_del_fns()[type]);
		return (NULL);
	}
	return (l->container);
}

t_lst			*ast_lap_build_items(t_lst *tokens,
							t_ast_type type, struct s_ast *ast)
{
	t_ast_lap		l;

	l.last_sep = NULL;
	l.container = twl_lst_new();
	while (42)
	{
		token_mgr_pop_linebreak(tokens);
		alias_mgr_expan_tokens(shenv_singleton()->shenv_alias, tokens, ast);
		if (should_break_fn(tokens, type, l.last_sep))
			break ;
		l.last_sep = NULL;
		l.item = ast_lap_new_from_tokens_fns()[type](tokens, ast);
		if (ast_has_error(ast))
		{
			ast_lap_del_fns()[type](l.item);
			twl_lst_del(l.container, ast_lap_del_fns()[type]);
			return (NULL);
		}
		twl_lst_push_back(l.container, l.item);
		if (!is_type_separator(type, token_mgr_first(tokens)))
			break ;
		ast_lap_set_separator_fns()[type](l.item, token_mgr_first(tokens));
		l.last_sep = twl_lst_pop_front(tokens);
	}
	return (ast_lap_build_items_end_fn(tokens, type, ast, &l));
}
