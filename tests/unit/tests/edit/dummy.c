#include <project.h>

#include "twl_arr.h"

extern char	**environ;

static void simple_test(t_test *test)
{
	mt_assert(0);
}

void	suite_get_env(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
