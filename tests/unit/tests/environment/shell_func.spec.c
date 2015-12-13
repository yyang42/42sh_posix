#include <project.h>

#include "environment.h"
#include "unset.h"
#include "twl_dict.h"

static void add_shell_func(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	environment_add_shell_func(env, "lol", "echo pouet");
	mt_assert(twl_dict_len(env->shell_func) == 1);
	environment_add_shell_func(env, "pouet", "exec $*");
	environment_del(env);
}

static void unset_shell_func(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	environment_add_shell_func(env, "lol", "echo pouet");
	mt_assert(twl_dict_len(env->shell_func) == 1);
	test_unset("unset -f lol", env);
	mt_assert(twl_dict_len(env->shell_func) == 0);
	environment_del(env);
}


void	suite_shell_func(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, add_shell_func);
	SUITE_ADD_TEST(suite, unset_shell_func);
}
