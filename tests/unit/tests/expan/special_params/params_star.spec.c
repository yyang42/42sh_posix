#include <project.h>

#include "environment.h"
#include "expan/expan_exec.h"
#include "builtin/set.h"
#include "builtin/export.h"

static void simple_star(t_test *test)
{
	char			*ret;
	t_environment	*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	export("export IFS=[", env);
	set("set lol pouet", env);
	ret = test_params_star(env, false);
	mt_assert(twl_strcmp(ret,"lol pouet") == 0);
	free(ret);
	environment_del(env);
}



void	suite_params_star(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_star);
}
