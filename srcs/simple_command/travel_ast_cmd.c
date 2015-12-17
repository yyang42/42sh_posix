#include "simple_command.h"

static void	use_builtin(t_simple_command *cmd, char *builtin, char *string)
{
	void *func;
	void (*f)(char *str);

	func = twl_dict_get(cmd->builtin_func, builtin);
	if (func)
	{
		f = func;
		f(string);
	}
}

static char	*check_cmd_is_built_in(void *cmd_field_)
{
	t_ast_cmd_field	*cmd_field;
	t_ast_string	*string;

	cmd_field = cmd_field_;
	string = (t_ast_string*)twl_lst_first(cmd_field->items);
	if (is_builtin(string->text))
		return (string->text);
	else
		return (NULL);
}

void travel_ast_cmd(t_simple_command *cmd, void *ast_node)
{
	t_ast_cmd *ast_cmd;

	(void)cmd;
	ast_cmd = ast_node;
	if (ast_cmd->redir_in != NULL)
	{

	}
	if (ast_cmd->redir_out != NULL)
	{

	}
	path = check_cmd_is_built_in(twl_lst_first(ast_cmd->strings));
	if ( path != NULL)
	{
		twl_printf("%s\n", "Builtin Detected");
		tmp = concatenate_ast_cmd(ast_cmd->strings);
		use_builtin(cmd, path, tmp);
		free(tmp);
	}
}
