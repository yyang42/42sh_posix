#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(000, "case", "case", false);
mt_test_ast_open_stack(001, "case a", "case", false);
mt_test_ast_open_stack(002, "case a b", "case", false);
mt_test_ast_open_stack(003, "case a b in", "case", false);
mt_test_ast_open_stack(004, "case a in\n a) echo abc", "case", false);
mt_test_ast_open_stack(005, "case a in\n a) echo abc\n", "case", false);
mt_test_ast_open_stack(006, "case a in\n a) echo abc;;", "case", false);
mt_test_ast_open_stack(007, "case a in\n\n a) echo abc;;", "case", false);

void	suite_ast_syntax_error_open_stack_case(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_000);
	SUITE_ADD_TEST(suite, test_001);
	SUITE_ADD_TEST(suite, test_002);
	SUITE_ADD_TEST(suite, test_003);
	SUITE_ADD_TEST(suite, test_004);
	SUITE_ADD_TEST(suite, test_005);
	SUITE_ADD_TEST(suite, test_006);
	SUITE_ADD_TEST(suite, test_007);
}
