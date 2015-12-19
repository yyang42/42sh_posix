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

#include "twl_arr.h"
#include "utils.h"

static void			build(t_ast_list *list, t_ast *ast)
{
	twl_lst_push(list->andors, ast_build_andor(ast));
}

t_ast_list			*ast_build_list(t_ast *ast)
{
	t_ast_list		*list;

	list = ast_list_new();
	list->index = ast->parser->index;
	while (parser_remain_len(ast->parser))
	{
		build(list, ast);
		if (parser_is_list_elem(ast->parser))
			ast->parser->index += 1; // skip separator
		else
			break ;
	}
	return (list);
}
