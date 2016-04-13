#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "{ cmd_level_1 ;}; {\n", "SyntaxError 1 : Syntax error near '{' : Brace group missing compound list", false);
mt_test_ast_error(02, "{ { }\n", "SyntaxError 1 : Syntax error near '{' : Brace group missing compound list", false);
mt_test_ast_error(03, "{ echo a }\n", "SyntaxError 1 : Syntax error near '{'", false);
mt_test_ast_error(04, "{ } {}", "SyntaxError 1 : Syntax error near '{' : Brace group missing compound list", false);

void	suite_ast_syntax_error_brace_group(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
}
