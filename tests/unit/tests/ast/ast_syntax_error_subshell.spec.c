#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "(cmd_level_1); (\n", "SyntaxError 1:16 : Matching ')' not found", false);

mt_test_ast_error(02, "( ( )\n", "SyntaxError 1:1 : Matching ')' not found", true);

void	suite_ast_syntax_error_subshell(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
}
