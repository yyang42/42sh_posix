#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "echo abcd &&\n",
	"SyntaxError 1:11 : Syntax error near '&&'", true);
mt_test_ast_error(02, "echo abcd &&",
	"SyntaxError 1:11 : Syntax error near '&&'", false);
mt_test_ast_error(03, "echo abcd && &&",
	"SyntaxError 1:14 : Syntax error near '&&' : Empty simple command", false);
mt_test_ast_error(04, "echo abcd && ||",
	"SyntaxError 1:14 : Syntax error near '||' : Empty simple command", false);
mt_test_ast_error(05, "&&",
	"SyntaxError 1:1 : Syntax error near '&&' : Empty simple command", false);
mt_test_ast_error(06, "echo abcd ||\n",
	"SyntaxError 1:11 : Syntax error near '||'", false);

void	suite_ast_syntax_error_andor(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
}
