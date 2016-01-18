#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "ls; while",
	"SyntaxError 1:5 : Syntax error near 'while' : Missing condition", true);

mt_test_ast_error(02, "ls; while ; do echo abc; done",
	"SyntaxError 1:5 : Syntax error near 'while'", true);

void	suite_ast_syntax_error_while_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
}
