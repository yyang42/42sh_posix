#include <project.h>

#include "ast/ast.h"

static void test_match(t_test *test)
{
	char			*open;

	open = ast_check_open("$( $((");
	mt_assert(strcmp(open, "$((") == 0);
	free(open);
}

static void test_not_match(t_test *test)
{
	char			*open;

	open = ast_check_open("bla");
	mt_assert(open == NULL);
	free(open);
}

void	suite_ast_check_open(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_match);
	SUITE_ADD_TEST(suite, test_not_match);
}
