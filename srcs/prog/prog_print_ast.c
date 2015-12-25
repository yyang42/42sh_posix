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

#include "prog.h"

#include "ast/ast.h"
#include "twl_xstdio.h"

void				prog_print_ast(t_prog *prog)
{
	t_xopt			*xopt;
	char			*str;
	t_ast			*ast;

	xopt = xopt_singleton();
	if (xopt->print_ast && twl_lst_len(xopt->opt->args))
	{
		str = twl_file_to_str(twl_lst_get(xopt->opt->args, 0));
		ast = ast_new(str);
		ast_build2(ast);
		ast_print_tokens(ast);
		str = ast_str(ast);
		twl_putstr(str);
		ast_del(ast);
		free(str);
	}
	(void)prog;
}
