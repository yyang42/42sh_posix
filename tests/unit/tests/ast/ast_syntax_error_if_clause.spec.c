#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "echo abc; if true; then echo abc;fu",
	"SyntaxError 1:11 : Syntax error near 'if' : Missing 'fi'", false);
mt_test_ast_error(02, "ls; if true; echo abc;fi",
	"SyntaxError 1:5 : Syntax error near 'if' : Missing 'then'", false);
mt_test_ast_error(03, "ls; if true; then echo abc; elif true; echo abc ; fi",
	"SyntaxError 1:29 : Syntax error near 'elif' : Missing 'then'", false);
mt_test_ast_error(04, "ls; if true; then ls; else echo | ;fi",
	"SyntaxError 1:35 : Syntax error near ';' : Empty simple command", false);

void	suite_ast_syntax_error_if_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
}
