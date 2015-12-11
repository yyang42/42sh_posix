#include <project.h>

#include "ast/ast.h"

static void sandbox(t_test *test)
{
	t_ast			*ast;

	ast = ast_new("if [ 2 -eq 2 ] ; then echo YES; else echo NO ; fi ; echo abc");
	ast_print(ast);
	mt_assert(true);
}

void	suite_ast_sandbox(t_suite *suite)
{
	SUITE_ADD_TEST(suite, sandbox);
}
