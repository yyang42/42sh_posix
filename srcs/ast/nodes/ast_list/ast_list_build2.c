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

static void			build(t_ast_list *list, t_parser *parser)
{
	(void)list;
	(void)parser;
}

t_ast_list			*ast_list_build2(t_parser *parser)
{
	t_ast_list	*list;

	list = ast_list_new();

	while (true)
	{
		build(list, parser);
		if (parser_cchar(parser) != ';')
			break ;
	}
	(void)parser;
	return (list);
}
