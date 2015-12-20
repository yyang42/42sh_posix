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
#include "ast/nodes/ast_cmd.h"
#include "ast/nodes/ast_cmd_subshell.h"
#include "ast/nodes/ast_comp_cmd.h"

t_ast_comp_cmd		*ast_build_comp_cmd(t_ast *ast)
{
	t_ast_comp_cmd	*comp_cmd;

	comp_cmd = ast_comp_cmd_new();
	comp_cmd->cmd = ast_build_cmd_subshell(ast);
	return (comp_cmd);
}
