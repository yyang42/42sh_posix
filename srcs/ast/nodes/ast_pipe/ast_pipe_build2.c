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

#include "ast/nodes/ast_pipe.h"
#include "ast/nodes/ast_pipe.h"

static void			build(t_ast_pipe *pipe, t_parser *parser)
{
	// twl_lst_push(pipe->pipes, ast_pipe_build2(parser));
	twl_lst_push(pipe->pipes, ast_pipe_new());
	while (parser_remain_len(parser))
	{
		if (parser_is_pipe_elem(parser) || parser_is_andor(parser) || parser_cchar(parser) == '\n')
			break ;
		parser->index++;
	}
}

t_ast_pipe			*ast_pipe_build2(t_parser *parser)
{
	t_ast_pipe		*pipe;

	pipe = ast_pipe_new();
	// // twl_printf("pipe parser {%s}\n", parser_cstr(parser));
	while (parser_remain_len(parser))
	{
		// twl_printf("== before build {%s}\n", parser_cstr(parser));
		build(pipe, parser);
		// twl_printf("== after build {%s}\n", parser_cstr(parser));
		if (parser_is_pipe_elem(parser))
			parser->index += 2; // skip separator
		else
			break ;
		// twl_printf("== after build2 {%s}\n", parser_cstr(parser));
	}
	// twl_printf("== end pipe {%s}\n", parser_cstr(parser));
	(void)parser;
	(void)build;
	return (pipe);
}
