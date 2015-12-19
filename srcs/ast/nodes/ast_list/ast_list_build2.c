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

#include "ast/nodes/ast_list.h"
#include "ast/nodes/ast_andor.h"

static bool			is_list_elem_sep(t_parser *parser)
{
	return (parser_cchar(parser) == '\n');
}

static void			build(t_ast_list *list, t_parser *parser)
{
	twl_lst_push(list->andors, ast_andor_build2(parser));
	while (parser_remain_len(parser))
	{
		if (is_list_elem_sep(parser))
			break ;
		parser->index++;
	}
}

t_ast_list			*ast_list_build2(t_parser *parser)
{
	t_ast_list		*list;

	list = ast_list_new();
	while (parser_remain_len(parser))
	{
		build(list, parser);
		if (!is_list_elem_sep(parser))
			break ;
		parser->index += 1; // skip separator
	}
	return (list);
}
