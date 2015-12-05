#include <project.h>

#include "utils.h"

static void test_that_should_pass(t_test *test)
{
	mt_assert(demo_sum(35, 7) == 42);
}

void	suite_demo_sum(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_that_should_pass);
}
