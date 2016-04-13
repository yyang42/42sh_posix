#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "abc (", "SyntaxError 1 : Syntax error near '('", false);
mt_test_ast_error(02, "echo \"", "SyntaxError 1 : looking for matching `\"'", false);

void	suite_ast_syntax_error_exec(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
}
