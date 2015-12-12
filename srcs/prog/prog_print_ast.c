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

void				prog_print_ast(t_prog *prog)
{
	t_xopt			*opt;
	char			*ast_str;
	t_ast			*ast;

	opt = xopt_singleton();
	if (opt->print_ast && opt->command)
	{
		ast = ast_new(opt->command);
		ast_build(ast);
		ast_str = ast_to_str(ast);
		twl_putstr(ast_str);
		free(ast_str);
	}
	(void)prog;
}
