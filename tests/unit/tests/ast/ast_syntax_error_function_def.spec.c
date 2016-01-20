#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "abc ()",
	"SyntaxError 1:1 : Syntax error near 'abc' : Missing compound command", false);

mt_test_ast_error(02, "abc () {",
	"SyntaxError 1:8 : Syntax error near '{'", false);

void	suite_ast_syntax_error_function_def(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_02);
}
