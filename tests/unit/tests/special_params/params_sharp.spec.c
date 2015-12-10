#include <project.h>

#include "environment.h"
#include "special_params.h"
#include "set.h"

static void simple_test(t_test *test)
{
	t_environment	*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	test_set("set lol pouet", env);
	mt_assert(twl_strcmp(test_params_sharp(env),"2") == 0);
	test_set("set lol", env);
	mt_assert(twl_strcmp(test_params_sharp(env),"1") == 0);
	environment_del(env);
}

void	suite_params_sharp(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_test);
}
