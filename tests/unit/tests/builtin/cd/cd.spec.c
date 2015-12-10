#include <project.h>

#include "env.h"
#include <stdlib.h>
#include <string.h>
#include "twl_stdio.h"

static void test_cd(t_test *test)
{
	(void)test;
	cd("cd");
}

void	suite_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_cd);
}
