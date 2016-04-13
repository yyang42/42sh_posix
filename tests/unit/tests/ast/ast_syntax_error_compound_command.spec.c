#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "( echo abc ) echo 123", "SyntaxError 1 : Unexpected token near 'echo'", false);
mt_test_ast_error(02, "( echo abc ) (echo abc)", "SyntaxError 1 : Syntax error near '('", false);
mt_test_ast_error(03, "{ echo abc; } echo 123", "SyntaxError 1 : Unexpected token near 'echo'", false);

void	suite_ast_syntax_error_compound_command(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
}
