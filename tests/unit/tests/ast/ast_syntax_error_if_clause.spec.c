#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "if true; then echo abc;", "SyntaxError 1:1 : Closing token for 'if' not found", false);
mt_test_ast_error(02, "if true; echo abc;fi", "SyntaxError 1:4 : 'then' token is expected but not found", false);
mt_test_ast_error(03, "if true; then echo abc; elif true; echo abc ; fi", "SyntaxError 1:30 : 'then' token is expected but not found", false);

void	suite_ast_syntax_error_if_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
}
