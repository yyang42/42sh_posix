#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "if true; then echo abc;", "SyntaxError 1:1 : Closing token for 'if' not found", false);

void	suite_ast_syntax_error_if_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
}
