#include <project.h>

#include "ast/ast.h"

static void sandbox(t_test *test)
{
	t_ast			*ast;

	ast = ast_new("echo 111;if true;then echo aaa;else echo bbb;fi;echo ccc");
	ast_build(ast);
	char			*out;
	out = ast_to_str(ast);
	printf("======\n");
	printf("%s", out);
	printf("======\n");
	char			*expected =   "COMPOUND_STMT\n" \
								  "  IF_STMT\n" \
								  "    COMPOUND_STMT\n" \
								  "      STRING_LITERAL true\n" \
								  "    COMPOUND_STMT\n" \
								  "      CMD_STMT\n" \
								  "        STRING_LITERAL echo\n" \
								  "        STRING_LITERAL aaa\n" \
								  "    COMPOUND_STMT\n" \
								  "      CMD_STMT\n" \
								  "        STRING_LITERAL echo\n" \
								  "        STRING_LITERAL bbb\n" \
								  "  CMD_STMT\n" \
								  "    STRING_LITERAL echo\n" \
								  "    STRING_LITERAL bbb\n";
	mt_assert(strcmp(out, expected) == 0);
}

void	suite_ast_sandbox(t_suite *suite)
{
	SUITE_ADD_TEST(suite, sandbox);
}
