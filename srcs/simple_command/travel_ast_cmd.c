#include "simple_command.h"

static char	*check_cmd_is_built_in(t_ast_cmd *ast_cmd)
{
	char *cmd;

	cmd = get_cmd_name_from_ast_cmd(ast_cmd);
	if (is_builtin(cmd))
		return (cmd);
	else
		return (NULL);
}

void travel_ast_cmd(t_simple_command *cmd, void *ast_node)
{
	t_ast_cmd 	*ast_cmd;
	char		*path;

	(void)cmd;
	ast_cmd = ast_node;
	if (ast_cmd->redir_in != NULL)
	{

	}
	if (ast_cmd->redir_out != NULL)
	{

	}
	path = check_cmd_is_built_in(ast_cmd);
	if (path != NULL)
		exec_simple_command_builtin(ast_cmd, cmd, path);
}
