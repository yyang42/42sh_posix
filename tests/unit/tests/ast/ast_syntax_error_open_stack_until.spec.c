#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(001, "until", "until", false);
mt_test_ast_open_stack(002, "until true", "until", false);
mt_test_ast_open_stack(003, "until true; do", "do", false);
mt_test_ast_open_stack(004, "until true; do echo abc", "do", false);

void	suite_ast_syntax_error_open_stack_until(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_001);
	SUITE_ADD_TEST(suite, test_002);
	SUITE_ADD_TEST(suite, test_003);
	SUITE_ADD_TEST(suite, test_004);
}
