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

mt_test_macro(01, "(cmd_level_1); (\n", "SyntaxError: Expected ')' but found EOF", false);
mt_test_macro(02, "echo abc |\n",       "SyntaxError: Expected input after '|' but found nothing", false);

void	suite_ast_syntax_error(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_01);
	SUITE_ADD_TEST(suite, test_02);
}
