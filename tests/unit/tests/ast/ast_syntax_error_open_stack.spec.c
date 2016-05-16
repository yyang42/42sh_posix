#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(01, "$(", "$(", false);
mt_test_ast_open_stack(02, "${$(", "${_$(", false);
mt_test_ast_open_stack(03, "${}$(", "$(", false);
mt_test_ast_open_stack(04, "${$(}", "${_$(", false);
mt_test_ast_open_stack(05, "'\"", "'_\"", false);
mt_test_ast_open_stack(06, "", "", false);
mt_test_ast_open_stack(07, "$( \"$(", "$(_\"_$(", false);
mt_test_ast_open_stack(101, "((", "(", false);
mt_test_ast_open_stack(102, "(", "(", false);
mt_test_ast_open_stack(103, "{", "{", false);
mt_test_ast_open_stack(104, "{ $(", "$(", false);
// mt_test_ast_open_stack(105, "{ ( echo abc; {", "{", true); // not handled yet

void	suite_ast_syntax_error_open_stack(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
	SUITE_ADD_TEST(suite, test_07);
	SUITE_ADD_TEST(suite, test_101);
	SUITE_ADD_TEST(suite, test_102);
	SUITE_ADD_TEST(suite, test_103);
	SUITE_ADD_TEST(suite, test_104);
	// SUITE_ADD_TEST(suite, test_105);
}
