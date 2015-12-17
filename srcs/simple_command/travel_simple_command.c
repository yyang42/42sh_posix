#include "simple_command.h"

void travel_simple_command(void *ast_node)
{
	if (ast_node_get_type(ast_node) == AST_LIST)
	{
		t_ast_list		*ast_list = ast_node;
		twl_printf("%s\n", "Root Detected");
		twl_lst_iter0(ast_list->items, travel_simple_command);
	}
	else if (ast_node_get_type(ast_node) == AST_CMD_FIELD)
	{
		twl_printf("%s\n", "AST CMD FIELD Detected");
	}
	else if (ast_node_get_type(ast_node) == AST_CMD)
	{
		twl_printf("%s\n", "AST CMD Detected");
	}
}
