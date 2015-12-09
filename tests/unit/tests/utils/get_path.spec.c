#include <project.h>

#include "utils.h"
#include <stdlib.h>

static void test_get_paths(t_test *test)
{
	char *paths;
	char *fpaths;

	(void)test;
	fpaths = getenv("PATH");
	paths = twl_strjoinarr((const char **)utils_get_paths(), ":");
	mt_assert(twl_strcmp(fpaths, paths) == 0);
}

void	suite_get_path(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_get_paths);
}
