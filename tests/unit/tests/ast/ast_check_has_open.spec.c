#include <project.h>

#include "ast/ast.h"

static void test_match1(t_test *test)
{
	mt_assert(ast_check_has_open("$( $((") == true);
}

static void test_match2(t_test *test)
{
	mt_assert(ast_check_has_open("$(") == true);
}

static void test_not_match(t_test *test)
{
	mt_assert(ast_check_has_open("bla") == false);
}

void	suite_ast_check_has_open(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_match1);
	SUITE_ADD_TEST(suite, test_match2);
	SUITE_ADD_TEST(suite, test_not_match);
}
