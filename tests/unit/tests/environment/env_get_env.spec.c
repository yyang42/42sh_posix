#include <project.h>

#include "twl_arr.h"

#include "environment.h"

extern char	**environ;

static void copied_env_is_equal_to_environ(t_test *test)
{
	int					i;
	t_lst_elem__		*temp;
	t_environment		*env;
	t_environment_var	*var;
	char				*str;

	(void)test;
	env = environment_new();
	environment_init(env);
	i = 0;
	temp = env->env_vars->head;
	while (environ[i] != NULL && temp != NULL)
	{
		var = (t_environment_var*)temp->data;
		str = twl_strjoin(var->evar_key, "=");
		str = twl_strjoinfree(str, var->evar_value, 'l');
		mt_assert(twl_strcmp(environ[i], str) == 0);
		i++;
		temp = temp->next;
		free(str);
	}
	environment_del(env);
}

static void test_set_env(t_test *test)
{
	(void)test;
	t_environment		*env;

	env = environment_new();
	environment_init(env);
	mt_assert(environment_getenv_value(env, "_key") == NULL);
	mt_assert(environment_getenv_value(env, "PATH") != NULL);
	environment_setenv(env, "_key=_value");
	mt_assert(twl_strcmp(environment_getenv_value(env, "_key"), "_value") == 0);
	environment_setenv(env, "_key=_new_value");
	mt_assert(twl_strcmp(environment_getenv_value(env, "_key"), "_new_value") == 0);
	environment_setenv(env, "_key=");
	mt_assert(twl_strcmp(environment_getenv_value(env, "_key"), "") == 0);
	environment_setenv(env, "_key========POUET==POUET=POUET==");
	mt_assert(twl_strcmp(environment_getenv_value(env, "_key"), "=======POUET==POUET=POUET==") == 0);
	environment_del(env);
}

static void test_unset_env(t_test *test)
{
	(void)test;
	t_environment		*env;

	env = environment_new();
	environment_init(env);
	environment_setenv(env, "test=_value");
	mt_assert(environment_getenv_value(env, "test") != NULL);
	environment_unsetenv(env, "test");
	mt_assert(environment_getenv_value(env, "test") == NULL);
	mt_assert(environment_getenv_value(env, "test2") == NULL);
	environment_unsetenv(env, "not_found");
	environment_del(env);
}

static void	test_set_get_env_value(t_test *test)
{
	(void)test;
	t_environment		*env;

	env = environment_new();
	environment_setenv_value(env, "hello", "pouet", 1);
	mt_assert(twl_strcmp(environment_getenv_value(env, "hello"), "pouet") == 0);
	environment_setenv_value(env, "hello", "", 1);
	mt_assert(twl_strcmp(environment_getenv_value(env, "hello"), "") == 0);
	environment_setenv_value(env, "hello", "=======POUET==POUET=POUET==", 1);
	mt_assert(twl_strcmp(environment_getenv_value(env, "hello"), "=======POUET==POUET=POUET==") == 0);
	mt_assert(environment_getenv_value(env, "not_found") == NULL);
	environment_del(env);
}

static void	test_clone(t_test *test)
{
	(void)test;
	t_environment		*env;
	t_environment		*clone;

	env = environment_new();
	environment_setenv_value(env, "quiche", "lorraine", 1);
	clone = environment_clone(env);
	environment_unsetenv(env, "quiche");
	environment_setenv_value(env, "tarte", "aupomme", 1);
	mt_assert(twl_strcmp(environment_getenv_value(clone, "quiche"), "lorraine") == 0);
	mt_assert(environment_getenv_value(clone, "tarte") == NULL);
	environment_del(env);
	environment_del(clone);
}

static void test_get_paths(t_test *test)
{
	char			*paths;
	char			*fpaths;
	t_environment	*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	fpaths = getenv("PATH");
	char			**path_arr;
	path_arr = environment_get_paths(env);
	paths = twl_strjoinarr((const char **)path_arr, ":");
	mt_assert(twl_strcmp(fpaths, paths) == 0);
	environment_del(env);
	twl_arr_del(path_arr, free);
	free(paths);
}

void	suite_env_get_env(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, copied_env_is_equal_to_environ);
	SUITE_ADD_TEST(suite, test_set_env);
	SUITE_ADD_TEST(suite, test_unset_env);
	SUITE_ADD_TEST(suite, test_set_get_env_value);
	SUITE_ADD_TEST(suite, test_clone);
	SUITE_ADD_TEST(suite, test_get_paths);
}
