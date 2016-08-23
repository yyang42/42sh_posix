#include <project.h>

#include "ast/ast.h"

mt_test_ast_open_stack(01, "BSDTAR(1)                 BSD General Commands Manual                BSDTAR(1)", "", false);

void	suite_ast_syntax_error_open_stack_man_tar(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
}
