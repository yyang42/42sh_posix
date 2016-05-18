#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(001, "cat << EOF\nabc\n123\n", "EOF", false);
mt_test_ast_open_stack(002, "cat << ABC\nabc\n123\n", "ABC", false);
mt_test_ast_open_stack(003, "cat << ABC\n", "ABC", false);

void	suite_ast_syntax_error_open_stack_heredoc(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_001);
	SUITE_ADD_TEST(suite, test_002);
	SUITE_ADD_TEST(suite, test_003);
}
