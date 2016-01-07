#include <project.h>

#include "environment.h"
#include "special_params.h"
#include "set.h"

static void simple_test(t_test *test)
{
	char			*ret;
	t_environment	*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	ret = test_params_at(env);
	mt_assert(twl_strcmp(ret,"") == 0);
	free(ret);
	set("set lol", env);
	ret = test_params_at(env);
	mt_assert(twl_strcmp(ret,"lol") == 0);
	free(ret);
	set("set lol pouet", env);
	ret = test_params_at(env);
	mt_assert(twl_strcmp(ret,"lol pouet") == 0);
	free(ret);
	environment_del(env);
}

void	suite_params_at(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_test);
}
