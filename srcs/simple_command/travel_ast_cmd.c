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

#include "simple_command.h"

<<<<<<< 08658cc5484e6f7c617ecf8955df8f244e79fe64
static char	*check_cmd_is_built_in(t_ast_cmd *ast_cmd)
=======
static char    *check_cmd_is_built_in(t_ast_cmd *ast_cmd)
{
    char *cmd;

    cmd = get_cmd_name_from_ast_cmd(ast_cmd);
    if (is_builtin(cmd))
        return (cmd);
    else
        return (NULL);
}

static char *can_use_binary(t_ast_cmd *ast)
{
	binary = get_cmd_name_from_ast_cmd(ast);
	if (binary)
	{
		binary_path = get_binary_path(binary);
		if (binary_path)
		{
			if (file_isexecutable(binary_path))
			{
				return (binary_path);
			}
		}
		else
			error_file_not_found(binary);
	}
	return (NULL);
}

void travel_ast_cmd(t_simple_command *cmd, void *ast_node)
{
	t_ast_cmd 	*ast_cmd;
	char		*path;

	ast_cmd = ast_node;
	path = check_cmd_is_built_in(ast_cmd);
	if (path)
		execute_builtin(cmd, ast_cmd, path);
	else
	{
		path = can_use_binary(ast_cmd);
		if (path)
		{
			execute_binary(ast_cmd, path);
			free(path);
		}
	}
}
