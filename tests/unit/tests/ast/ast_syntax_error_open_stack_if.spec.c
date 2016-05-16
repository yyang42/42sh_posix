#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(110, "if", "if", false);
mt_test_ast_open_stack(111, "if true", "if", false);
mt_test_ast_open_stack(112, "if true; then", "then", false);
mt_test_ast_open_stack(113, "if true; then echo abc", "fi", false);
mt_test_ast_open_stack(114, "if true; then echo abc; elif", "if", false);
mt_test_ast_open_stack(115, "if true; then echo abc; elif true", "if", false);
mt_test_ast_open_stack(116, "if true; then echo abc; elif true; then ", "then", false);
mt_test_ast_open_stack(117, "if true; then echo abc; elif true; then echo abc", "fi", false);

void	suite_ast_syntax_error_open_stack_if(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_110);
	SUITE_ADD_TEST(suite, test_111);
	SUITE_ADD_TEST(suite, test_112);
	SUITE_ADD_TEST(suite, test_113);
	SUITE_ADD_TEST(suite, test_114);
	SUITE_ADD_TEST(suite, test_115);
	SUITE_ADD_TEST(suite, test_116);
	SUITE_ADD_TEST(suite, test_117);
}
