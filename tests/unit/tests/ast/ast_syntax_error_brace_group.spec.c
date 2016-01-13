#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "{cmd_level_1}; {\n", "SyntaxError 1:14 : Syntax error near ';'", true);

mt_test_ast_error(02, "{ { }\n", "SyntaxError 1:6 : Syntax error near '\n'", true);

void	suite_ast_syntax_error_brace_group(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
}
