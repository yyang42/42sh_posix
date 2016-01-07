#include <project.h>

#include "environment.h"
#include "set.h"
#include "export.h"

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
	// export("export  -p", env);
	mt_assert((j - i) == 1);
	environment_del(env);
}

void            suite_builtin_export(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, value_is_empty);
	SUITE_ADD_TEST(suite, value_is_null);
}
