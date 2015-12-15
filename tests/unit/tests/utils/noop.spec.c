#include <project.h>

#include "utils.h"

static void noop(t_test *test)
{
	mt_assert(true != false);
}

void	suite_noop(t_suite *suite)
{
	SUITE_ADD_TEST(suite, noop);
}
