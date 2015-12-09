#include <project.h>

#include "env.h"
#include <stdlib.h>

static void test_env(t_test *test)
{
	(void)test;
	// env("env -i choucroute=garnie bash");
}

void	suite_env(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_env);
}
