#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "{cmd_level_1}; {\n", "SyntaxError 1:16 : Syntax error near '{'", false);

mt_test_ast_error(02, "{ { }\n", "SyntaxError 1:1 : Syntax error near '{'", false);

void	suite_ast_syntax_error_brace_group(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
}
