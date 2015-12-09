#include <project.h>

#include "utils.h"

static void test_get_paths(t_test *test)
{
	char **paths;

	(void)test;
	paths = utils_get_paths();
}

void	suite_get_path(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_get_paths);
}
