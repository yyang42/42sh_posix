#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "for",
	"SyntaxError 1:1 : Syntax error near 'for' : Missing 'NAME token'", true);
mt_test_ast_error(02, "echo abc; for 1234",
	"SyntaxError 1:11 : Syntax error near 'for' : invalid NAME token", true);
mt_test_ast_error(03, "echo abc; for hello",
	"SyntaxError 1:11 : Syntax error near 'for'", true);
mt_test_ast_error(04, "echo abc; for hello dooo ls; done",
	"SyntaxError 1:11 : Syntax error near 'for'", true);
mt_test_ast_error(05, "echo abc; for hello do ls; donex",
	"SyntaxError 1:11 : Syntax error near 'for'", true);
mt_test_ast_error(06, "echo abc; for in hello do ls; donex",
	"SyntaxError 1:11 : Syntax error near 'for'", true);

void	suite_ast_syntax_error_for_clause(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
}
