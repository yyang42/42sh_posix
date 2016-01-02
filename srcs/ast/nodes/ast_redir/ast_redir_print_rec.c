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

#include "ast/nodes/ast_redir.h"

void				ast_redir_print_rec(t_ast_redir *ast_redir, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_redir (");
	if (ast_redir->io_number != IO_NUMBER_NOT_DEFINED)
	{
		twl_printf("%d", ast_redir->io_number);
	}
	twl_printf("%s %s", ast_redir->operator, ast_redir->param);
	if (ast_redir->heredoc_text)
	{
		twl_printf_escape_nl(", heredoc=%.20s", ast_redir->heredoc_text);
	}
	twl_printf(")\n");
	depth++;
	(void)ast_redir;
}
