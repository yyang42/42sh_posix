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

#include <prog.h>
#include <ast/ast.h>

int					prog_run_input(t_prog *this, char *input)
{
	t_ast			*ast;
	int				ret;

	ast = ast_new(input);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		ast_del(ast);
		return (1);
	}
	ret = ast_exec(ast);
	ast_del(ast);
	return (ret);
	(void)this;
}
