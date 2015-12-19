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

void				ast_to_str_push_line(t_ast *ast, char *type, int index)
{
	char			*tmp;
	char			*code_seg;

	// code_seg = twl_strndup(ast->parser->raw + index, 20);
	// code_seg = twl_str_replace_free(code_seg, "\n", "\\n");
	twl_asprintf(&tmp, "%*s%s",
		ast->out_depth * AST_TAB_WIDTH, "", type);
	twl_lst_push(ast->out_lines, tmp);

	if (twl_strequ(type, "CMD_SIMPLE"))
	{
		code_seg = twl_strndup(ast->parser->raw + index, 20);
		code_seg = twl_str_replace_free(code_seg, "\n", "\\n");
		twl_lst_push(ast->out_lines, twl_strdup(" "));
		twl_lst_push(ast->out_lines, code_seg);
	}
	twl_lst_push(ast->out_lines, twl_strdup("\n"));
	// free(code_seg);
	(void)index;
}
