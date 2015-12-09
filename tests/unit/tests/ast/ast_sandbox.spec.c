#include <project.h>

#include "ast.h"

static void sandbox(t_test *test)
{
	t_ast			*ast;

	ast = ast_new("if [ 2 -eq 2 ] ; then echo abc ; fi");
	ast_print(ast);
	mt_assert(0);
}

void	suite_ast_sandbox(t_suite *suite)
{
	SUITE_ADD_TEST(suite, sandbox);
}
