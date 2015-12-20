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

static void			build(t_ast_andor_seq *andor, t_ast *ast)
{
	twl_lst_push(andor->pipes, ast_build_pipe(ast));
}

t_ast_andor_seq			*ast_build_andor_seq(t_ast *ast)
{
	t_ast_andor_seq		*andor;

	andor = ast_andor_seq_new(ANDOR_TYPE_AND);
	andor->index = ast->parser->index;
	while (parser_remain_len(ast->parser))
	{
		build(andor, ast);
		if (parser_is_andor(ast->parser))
			ast->parser->index += 2; // skip separator
		else
			break ;
	}
	return (andor);
}
