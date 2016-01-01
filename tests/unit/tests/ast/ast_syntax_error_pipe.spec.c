#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(02, "echo abc |\n",       				"SyntaxError 1:10 : Expected input after '|' but found nothing", false);
mt_test_ast_error(03, "echo abc | ; echo 123\n",       		"SyntaxError 1:10 : Expected input after '|' but found nothing", false);
mt_test_ast_error(04, "echo abc \necho 1 |\necho 123\n",    "SyntaxError 2:8 : Expected input after '|' but found nothing", false);
mt_test_ast_error(05, "echo abc\n\necho 123 |;",       		"SyntaxError 3:10 : Expected input after '|' but found nothing", false);

void	suite_ast_syntax_error_pipe(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
}
