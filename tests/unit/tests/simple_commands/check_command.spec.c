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

void	suite_check_command(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, test_is_builtin);
}
