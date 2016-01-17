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

#include "data.h"
#include "ast/ast_lap.h"
#include "ast/nodes/ast_pipe_item.h"

t_ast_lap_new_from_tokens_fn	*ast_lap_new_from_tokens_fns(void)
{
	static t_ast_lap_new_from_tokens_fn	fns[AST_TYPE_NBR];
	static bool									is_loaded = false;

	if (is_loaded == false)
	{
		fns[AST_TYPE_LIST_ITEM] = ast_list_item_new_from_tokens_void;
		fns[AST_TYPE_ANDOR_ITEM] = ast_andor_item_new_from_tokens_void;
		fns[AST_TYPE_PIPE_ITEM] = ast_pipe_item_new_from_tokens_void;
	}
	return (fns);
}

t_lst				**ast_lap_get_seps_list(void)
{
	static t_lst	*segs[AST_TYPE_NBR];
	static bool									is_loaded = false;

	if (is_loaded == false)
	{
		segs[AST_TYPE_LIST_ITEM] = data_list_separators();
		segs[AST_TYPE_ANDOR_ITEM] = data_andor_separators();
		segs[AST_TYPE_PIPE_ITEM] = data_pipe_separators();
	}
	return (segs);
}

t_ast_lap_set_separator_fn	*ast_lap_set_separator_fns(void)
{
	static t_ast_lap_set_separator_fn	fns[AST_TYPE_NBR];
	static bool									is_loaded = false;

	if (is_loaded == false)
	{
		fns[AST_TYPE_LIST_ITEM] = ast_list_item_set_separator_void;
		fns[AST_TYPE_ANDOR_ITEM] = ast_andor_item_set_separator_void;
		fns[AST_TYPE_PIPE_ITEM] = ast_pipe_item_set_separator_void;
	}
	return (fns);
}

t_lst				*ast_lap_build_items(t_lst *tokens,
							t_ast_type type,
							struct s_ast *ast)
{
	void			*item;
	t_lst			*container;
	t_token			*first;

	container = twl_lst_new();
	while (true)
	{
		token_mgr_pop_linebreak(tokens);
		if (twl_lst_len(tokens) == 0)
			break ;
		if (token_mgr_first_equ(tokens, "then")
			|| token_mgr_first_equ(tokens, "elif")
			|| token_mgr_first_equ(tokens, "else")
			|| token_mgr_first_equ(tokens, "fi")
			)
			break ;
		item = ast_lap_new_from_tokens_fns()[type](tokens, ast);
		twl_lst_push(container, item);
		first = token_mgr_first(tokens);
		if (first && twl_lst_find(ast_lap_get_seps_list()[type], twl_strequ_void, first->text))
		{
			t_token *sep = first;
			ast_lap_set_separator_fns()[type](item, first);
			twl_lst_pop_front(tokens);
			t_token *next_token = twl_lst_first(tokens);

			if (twl_strequ(sep->text, "&&")
					|| twl_strequ(sep->text, "||")
					|| twl_strequ(sep->text, "|")
					|| twl_strequ(sep->text, ";")
					|| twl_strequ(sep->text, "&")
				)
			{
				if (!next_token
					|| (twl_strequ(next_token->text, "&&")
						|| twl_strequ(next_token->text, "||")
						|| twl_strequ(next_token->text, "|")
						|| twl_strequ(next_token->text, ";")
						|| twl_strequ(next_token->text, "&")
						|| twl_strequ(next_token->text, "\n")
						)
					)
				{
					ast_set_error_msg_syntax_error_near(ast, sep);
					return (NULL);
				}
			}
		}
		else
		{
			break ;
		}
	}
	return (container);
	(void)type;
}
