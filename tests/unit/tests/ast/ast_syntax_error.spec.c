#include <project.h>

#include "ast/ast.h"

# define mt_test_macro(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_ast			*ast; \
		ast = ast_new(input); \
		if (debug) \
		{ \
			twl_printf("input    : %s\n", input); \
			twl_printf("actual   : %s\n", ast->error_msg); \
			twl_printf("expected : %s\n", expected); \
		} \
		mt_assert(ast->error_msg && strcmp(ast->error_msg, expected) == 0); \
		ast_del(ast); \
	}

mt_test_macro(01, "(cmd_level_1); (\n", "SyntaxError 1:16 : Expected ')' but found EOF", false);
mt_test_macro(02, "echo abc |\n",       "SyntaxError 1:10 : Expected input after '|' but found nothing", false);
mt_test_macro(03, "echo abc | ; echo 123\n",       "SyntaxError 1:10 : Expected input after '|' but found nothing", false);
mt_test_macro(04, "echo abc \necho 1 |\necho 123\n",       "SyntaxError 2:8 : Expected input after '|' but found nothing", false);
mt_test_macro(05, "echo abc\n\necho 123 |;",       "SyntaxError 3:10 : Expected input after '|' but found nothing", true);

void	suite_ast_syntax_error(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
	SUITE_ADD_TEST(suite, test_03);
	SUITE_ADD_TEST(suite, test_04);
	SUITE_ADD_TEST(suite, test_05);
}
