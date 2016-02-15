#include <project.h>

#include "environment.h"
#include "builtin/set.h"
#include "builtin/export.h"

static void     simple_test(t_test *test)
{
    t_environment		*env;
	int					i;
	int					j;

    (void)test;
    env = environment_new();
	environment_init(env);
	i = twl_lst_len(env->env_vars);
	export("export POPO=PAPA", env);
	j = twl_lst_len(env->env_vars);
    mt_assert((j - i) == 1);
	export("export PIPI=POPO", env);
	i = twl_lst_len(env->env_vars);
	mt_assert((i - j) == 1);
	environment_del(env);
}

static void     value_is_empty(t_test *test)
{
    t_environment		*env;
	int					i;
	int					j;

    (void)test;
    env = environment_new();
	environment_init(env);
	i = twl_lst_len(env->env_vars);
	export("export HOHO=", env);
	j = twl_lst_len(env->env_vars);
	mt_assert((j - i) == 1);
	environment_del(env);
}

static void     value_is_null(t_test *test)
{
    t_environment		*env;
	int					i;
	int					j;

    (void)test;
    env = environment_new();
	environment_init(env);
	i = twl_lst_len(env->env_vars);
	export("export HUHIAH", env);
	j = twl_lst_len(env->env_vars);
	mt_assert((j - i) == 1);
	environment_del(env);
}

static void     key_already_exists(t_test *test)
{
    t_environment		*env;
	int					i;
	int					j;

    (void)test;
    env = environment_new();
	environment_init(env);
	i = twl_lst_len(env->env_vars);
	export("export HOME=/tmp", env);
	j = twl_lst_len(env->env_vars);
	mt_assert(!twl_strcmp(environment_getenv_value(env, "HOME"), "/tmp"));
	mt_assert((j - i) == 0);
	export("export HOME=/", env);
	mt_assert(!twl_strcmp(environment_getenv_value(env, "HOME"), "/"));
	j = twl_lst_len(env->env_vars);
	mt_assert((j - i) == 0);
	environment_del(env);
}

void            suite_builtin_export(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, value_is_empty);
	SUITE_ADD_TEST(suite, value_is_null);
	SUITE_ADD_TEST(suite, key_already_exists);
}
