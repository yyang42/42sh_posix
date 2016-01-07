#include <project.h>

#include "environment.h"
#include "special_params.h"
#include "set.h"
#include "export.h"

static void unquoted_star(t_test *test)
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

static void quoted_star(t_test *test)
{
	char			*ret;
	t_environment	*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	export("export IFS=[", env);
	set("set lol pouet", env);
	ret = test_params_star(env, true);
	mt_assert(twl_strcmp(ret,"lol[pouet") == 0);
	free(ret);
	environment_del(env);
}

static void null_ifs(t_test *test)
{
	char			*ret;
	t_environment	*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	export("export IFS", env);
	set("set lol pouet", env);
	ret = test_params_star(env, true);
	mt_assert(twl_strcmp(ret,"lol pouet") == 0);
	free(ret);
	environment_del(env);
}

static void zero_ifs(t_test *test)
{
	char			*ret;
	t_environment	*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	export("export IFS=", env);
	set("set lol pouet", env);
	ret = test_params_star(env, true);
	mt_assert(twl_strcmp(ret,"lolpouet") == 0);
	free(ret);
	environment_del(env);
}

void	suite_params_star(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, unquoted_star);
	SUITE_ADD_TEST(suite, quoted_star);
	SUITE_ADD_TEST(suite, null_ifs);
	SUITE_ADD_TEST(suite, zero_ifs);
}
