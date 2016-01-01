#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(02, "echo abcd &&\n",       				"SyntaxError 1:11 : Expected input after '&&' but found nothing", true);

void	suite_ast_syntax_error_andor(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_02);
}
