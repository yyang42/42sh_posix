#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "ls; case",
	"SyntaxError 1:5 : Syntax error near 'case'", false);
mt_test_ast_error(02, "ls; case $abc",
	"SyntaxError 1:5 : Syntax error near 'case' : Missing 'in'", false);
mt_test_ast_error(03, "ls; case $abc in",
	"SyntaxError 1:5 : Syntax error near 'case'", false);
mt_test_ast_error(04, "ls; case $abc in\n1\necho abc",
	"SyntaxError 2:1 : Syntax error near '1' : Missing ')'", false);
mt_test_ast_error(05, "ls; case $abc in\n1)\necho abc",
	"SyntaxError 1:5 : Syntax error near 'case' : Missing 'esac'", false);
mt_test_ast_error(06, "ls; case $abc in\n1",
	"SyntaxError 2:1 : Syntax error near '1' : Missing ')'", false);
mt_test_ast_error(07, "ls; case aa in\n))\necho abc\nesac\n",
	"SyntaxError 2:1 : Unexpected token near ')'", false);
mt_test_ast_error(08, "ls; case aa in\n))\necho abc\nesac\n",
	"SyntaxError 2:1 : Unexpected token near ')'", false);

void	suite_ast_syntax_error_case_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
	SUITE_ADD_TEST(suite, test_07);
	SUITE_ADD_TEST(suite, test_08);
}
