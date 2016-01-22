#include <project.h>

#include "ast/ast.h"

mt_test_ast_error(01, "(cmd_level_1); (\n", "SyntaxError 1:16 : Syntax error near '('", false);
mt_test_ast_error(02, "( ( )\n", "SyntaxError 1:5 : Syntax error near ')' : Empty simple command", false);
mt_test_ast_error(03, "( ; ; )\n", "SyntaxError 1:3 : Syntax error near ';' : Empty simple command", false);
mt_test_ast_error(04, "( \n", "SyntaxError 1:1 : Syntax error near '('", false);
mt_test_ast_error(05, "()", "SyntaxError 1:2 : Syntax error near ')' : Empty simple command", false);
mt_test_ast_error(06, "123echo ( echo abc )", "SyntaxError 1:9 : Syntax error near '('", false);

void	suite_ast_syntax_error_subshell(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
	SUITE_ADD_TEST(suite, test_06);
}
