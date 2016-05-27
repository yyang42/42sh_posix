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
#include "data.h"

#include "ast/nodes/ast_compound_list.h"
#include "ast/ast_lap.h"

t_ast_compound_list	*ast_compound_list_new_from_tokens_wrap(t_lst *tokens,
								char *open, char *close, struct s_ast *ast)
{
	t_ast_compound_list			*this;

	if (twl_lst_len(tokens) == 0)
		return (NULL);
	if (token_mgr_first_equ(tokens, open) == false)
		return (NULL);
	twl_lst_pop_front(tokens);
	this = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_compound_list_del(this);
		return (NULL);
	}
	if (token_mgr_first_equ(tokens, close) == false)
	{
		if (twl_lst_len(tokens) == 0)
		{
			ast_add_to_open_stack(ast, "do");
		}
		ast_compound_list_del(this);
		return (NULL);
	}
	twl_lst_pop_front(tokens);
	return (this);
}
