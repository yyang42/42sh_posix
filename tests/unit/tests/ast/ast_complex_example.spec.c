#include <project.h>

#include "ast/ast.h"

static void simple_example(t_test *test)
{
	t_ast			*ast;

	ast = ast_new("echo 123;echo abc");
	ast_build(ast);
	char			*out;
	out = ast_to_str(ast);
	char			*expected =   "COMPOUND_STMT\n" \
								  "  CMD_STMT\n" \
								  "    STRING_LITERAL \"echo\"\n" \
								  "    STRING_LITERAL \"123\"\n" \
								  "  CMD_STMT\n" \
								  "    STRING_LITERAL \"echo\"\n" \
								  "    STRING_LITERAL \"abc\"\n";

	printf("== actual ======================\n");
	printf("%s", out);
	printf("== expected ====================\n");
	printf("%s", expected);
	printf("================================\n");
	mt_assert(strcmp(out, expected) == 0);
}

static void complex_example(t_test *test)
{
	t_ast			*ast;

	ast = ast_new("echo 111;if true;then echo aaa;else echo bbb;fi;echo ccc\n");
	ast_build(ast);
	char			*out;
	out = ast_to_str(ast);
	char			*expected =   "COMPOUND_STMT\n" \
								  "  CMD_STMT\n" \
								  "    STRING_LITERAL \"echo\"\n" \
								  "    STRING_LITERAL \"111\"\n" \
								  "  IF_STMT\n" \
								  "    COMPOUND_STMT\n" \
								  "      CMD_STMT\n" \
								  "        STRING_LITERAL \"true\"\n" \
								  "    COMPOUND_STMT\n" \
								  "      CMD_STMT\n" \
								  "        STRING_LITERAL \"echo\"\n" \
								  "        STRING_LITERAL \"aaa\"\n" \
								  "    COMPOUND_STMT\n" \
								  "      CMD_STMT\n" \
								  "        STRING_LITERAL \"echo\"\n" \
								  "        STRING_LITERAL \"bbb\"\n" \
								  "  CMD_STMT\n" \
								  "    STRING_LITERAL \"echo\"\n" \
								  "    STRING_LITERAL \"ccc\"\n";

	printf("== actual ======================\n");
	printf("%s", out);
	printf("== expected ====================\n");
	printf("%s", expected);
	printf("================================\n");
	mt_assert(strcmp(out, expected) == 0);
}

void	suite_ast_complex_example(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_example);
	SUITE_ADD_TEST(suite, complex_example);
}
