#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(001, "foo ()", "foo", false);
mt_test_ast_open_stack(002, "foo    ()", "foo", false);

void	suite_ast_syntax_error_open_stack_func_def(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_001);
	SUITE_ADD_TEST(suite, test_002);
}
