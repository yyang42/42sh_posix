#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "(cmd_level_1); (\n", "SyntaxError 1:16 : Syntax error near '('", true);

mt_test_ast_error(02, "( ( )\n", "SyntaxError 1:1 : Syntax error near '('", true);
mt_test_ast_error(03, "( ; ; )\n", "SyntaxError 1:3 : Syntax error near ';'", true);

void	suite_ast_syntax_error_subshell(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
}
