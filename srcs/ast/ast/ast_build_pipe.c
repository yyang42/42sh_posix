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

#include "ast/ast.h"
#include "ast/nodes/ast_pipe.h"

static void			build(t_ast_pipe *pipe, t_ast *ast)
{
	// twl_lst_push(pipe->pipes, ast_pipe_build2(parser));
	// twl_printf("parser %s\n", parser_cstr(ast->parser));
	twl_lst_push(pipe->pipes, ast_build_cmd(ast));
}

t_ast_pipe			*ast_build_pipe(t_ast *ast)
{
	t_ast_pipe		*pipe;

	pipe = ast_pipe_new();
	pipe->index = ast->parser->index;
	while (parser_remain_len(ast->parser))
	{
		build(pipe, ast);
		// twl_printf("parser %s\n", parser_cstr(ast->parser));
		if (parser_is_pipe_elem(ast->parser))
			ast->parser->index += 1; // skip separator
		else
			break ;
	}
	(void)ast->parser;
	(void)build;
	return (pipe);
}
