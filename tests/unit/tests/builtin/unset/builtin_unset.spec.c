#include <project.h>

#include "environment.h"
#include "unset.h"
#include "export.h"

static void 	unset_var(t_test *test)
{
	t_environment		*env;
	int					i;
	int					j;

	(void)test;
	env = environment_new();
	environment_init(env);
	export("export HAHA=pouet", env);
	i = twl_lst_len(env->env_vars);
	unset("unset HAHA", env);
	j = twl_lst_len(env->env_vars);
	mt_assert((i - j) == 1);
	environment_del(env);
}

static void 	unset_func(t_test *test)
{
	t_environment		*env;
	int					i;
	int					j;

	(void)test;
	env = environment_new();
	environment_init(env);
	environment_add_shell_func(env,"LOL", "echo pouet");
	i = twl_dict_len(env->shell_func);
	unset("unset LOL", env);
	j = twl_dict_len(env->shell_func);
	mt_assert((i - j) == 1);
	environment_del(env);
}

static void 	unset_var_not_func(t_test *test)
{
	t_environment		*env;
	int					i;
	int					j;
	int					k;
	int					l;

	(void)test;
	env = environment_new();
	environment_init(env);
	export("export LOL=pouet", env);
	environment_add_shell_func(env,"LOL", "echo pouet");
	i = twl_dict_len(env->shell_func);
	k = twl_lst_len(env->env_vars);
	unset("unset LOL", env);
	j = twl_dict_len(env->shell_func);
	l = twl_lst_len(env->env_vars);
	mt_assert((i - j) == 0);
	mt_assert((k - l) == 1);
	environment_del(env);
}

static void 	unset_both(t_test *test)
{
	t_environment		*env;
	int					i;
	int					j;
	int					k;
	int					l;

	(void)test;
	env = environment_new();
	environment_init(env);
	export("export LOL=pouet", env);
	environment_add_shell_func(env,"LOL", "echo pouet");
	i = twl_dict_len(env->shell_func);
	k = twl_lst_len(env->env_vars);
	unset("unset LOL", env);
	unset("unset LOL", env);
	j = twl_dict_len(env->shell_func);
	l = twl_lst_len(env->env_vars);
	mt_assert((i - j) == 1);
	mt_assert((k - l) == 1);
	environment_del(env);
}

void            suite_builtin_unset(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, unset_var);
	SUITE_ADD_TEST(suite, unset_func);
	SUITE_ADD_TEST(suite, unset_var_not_func);
	SUITE_ADD_TEST(suite, unset_both);
}
