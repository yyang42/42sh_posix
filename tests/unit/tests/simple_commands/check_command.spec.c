#include "simple_command.h"
#include <project.h>

static void test_is_builtin(t_test *test)
{
	(void)test;
	mt_assert(is_builtin("hello") == false);
	mt_assert(is_builtin("cd") == true);
	mt_assert(is_builtin("ls") == false);
	mt_assert(is_builtin("env") == true);
	mt_assert(is_builtin("") == false);
}

static void test_get_binary_path(t_test *test)
{
	(void)test;
	mt_assert(get_binary_path("pouet") == NULL);
	mt_assert(get_binary_path("ls") != NULL);
}

void	suite_check_command(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, test_is_builtin);
	SUITE_ADD_TEST(suite, test_get_binary_path);
}
