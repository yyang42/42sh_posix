#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "ls; until",
	"SyntaxError 1 : Syntax error near 'until' : Missing condition", false);

mt_test_ast_error(02, "ls; until ; do echo abc; done",
	"SyntaxError 1 : Syntax error near ';' : Empty simple command", false);

mt_test_ast_error(03, "ls; until true; echo abc; done",
	"SyntaxError 1 : Syntax error near 'until'", false);

mt_test_ast_error(04, "ls; until true; do ; done",
	"SyntaxError 1 : Syntax error near ';' : Empty simple command", false);

mt_test_ast_error(05, "echo abc; until true; do ; do",
	"SyntaxError 1 : Syntax error near ';' : Empty simple command", false);

void	suite_ast_syntax_error_until_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
}
