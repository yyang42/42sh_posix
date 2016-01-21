#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "ls; while",
	"SyntaxError 1:5 : Syntax error near 'while' : Missing condition", false);

mt_test_ast_error(02, "ls; while ; do echo abc; done",
	"SyntaxError 1:11 : Syntax error near ';' : Empty simple command", false);

mt_test_ast_error(03, "ls; while true; echo abc; done",
	"SyntaxError 1:5 : Syntax error near 'while'", false);

mt_test_ast_error(04, "ls; while true; do ; done",
	"SyntaxError 1:20 : Syntax error near ';' : Empty simple command", false);

mt_test_ast_error(05, "echo abc; while true; do ; do",
	"SyntaxError 1:26 : Syntax error near ';' : Empty simple command", false);

void	suite_ast_syntax_error_while_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
}
