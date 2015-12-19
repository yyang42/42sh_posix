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

#include "twl_xstring.h"

#include "ast/nodes/ast_andor.h"
#include "ast/nodes/ast_andor.h"

static bool			is_andor_elem_sep(t_parser *parser)
{
	return (twl_str_starts_with(parser_cstr(parser), "&&")
		|| twl_str_starts_with(parser_cstr(parser), "||"));
}

/*static void			build(t_ast_list *list, t_parser *parser)
{
	twl_lst_push(list->andors, ast_pipe_build2(parser));
	while (parser_cchar(parser))
	{
		if (parser_cchar(parser) == '\n')
			break ;
		parser->index++;
	}
}
*/

t_ast_andor			*ast_andor_build2(t_parser *parser)
{
	t_ast_andor		*andor;

	andor = ast_andor_new(ANDOR_TYPE_AND);
	while (true)
	{
		// build(andor, parser);
		if (!is_andor_elem_sep(parser))
			break ;
		parser->index += 2; // skip && and ||
	}
	return (andor);
}
