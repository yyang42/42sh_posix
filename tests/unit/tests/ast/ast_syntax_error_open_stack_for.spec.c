#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(001, "for", "for", false);
mt_test_ast_open_stack(002, "for i in", "for", false);
mt_test_ast_open_stack(003, "for i in a; do", "do", false);

void	suite_ast_syntax_error_open_stack_for(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_001);
	SUITE_ADD_TEST(suite, test_002);
	SUITE_ADD_TEST(suite, test_003);
}
