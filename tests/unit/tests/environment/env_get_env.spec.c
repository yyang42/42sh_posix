#include <project.h>

#include "twl_arr.h"

#include "shenv/shenv.h"

extern char	**environ;

static void copied_env_is_equal_to_environ(t_test *test)
{
	int					i;
	t_lst_elem__		*temp;
	t_shenv		*env;
	t_shvar	*var;
	char				*str;

	(void)test;
	env = shenv_new();
	shenv_init(env);
	i = 0;
	temp = env->shvars->head;
	while (environ[i] != NULL && temp != NULL)
	{
		var = (t_shvar*)temp->data;
		str = twl_strjoin(var->shvar_key, "=");
		str = twl_strjoinfree(str, var->shvar_value ? var->shvar_value : "", 'l');
		mt_assert(twl_strcmp(environ[i], str) == 0);
		i++;
		temp = temp->next;
		free(str);
	}
	shenv_del(env);
}

static void test_set_env(t_test *test)
{
	(void)test;
	t_shenv		*env;

	env = shenv_new();
	shenv_init(env);
	mt_assert(shenv_shvars_get_value(env, "_key") == NULL);
	mt_assert(shenv_shvars_get_value(env, "PATH") != NULL);
	shenv_shvars_set_split_by_equal(env, "_key=_value", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "_key"), "_value") == 0);
	shenv_shvars_set_split_by_equal(env, "_key=_new_value", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "_key"), "_new_value") == 0);
	shenv_shvars_set_split_by_equal(env, "_key=", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "_key"), "") == 0);
	shenv_shvars_set_split_by_equal(env, "_key========POUET==POUET=POUET==", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "_key"), "=======POUET==POUET=POUET==") == 0);
	shenv_del(env);
}

static void test_unset_env(t_test *test)
{
	(void)test;
	t_shenv		*env;

	env = shenv_new();
	shenv_init(env);
	shenv_shvars_set_split_by_equal(env, "test=_value", NULL);
	mt_assert(shenv_shvars_get_value(env, "test") != NULL);
	shenv_unsetenv(env, "test");
	mt_assert(shenv_shvars_get_value(env, "test") == NULL);
	mt_assert(shenv_shvars_get_value(env, "test2") == NULL);
	shenv_unsetenv(env, "not_found");
	shenv_del(env);
}

static void	test_set_get_env_value(t_test *test)
{
	(void)test;
	t_shenv		*env;

	env = shenv_new();
	shenv_shvars_set(env, "hello", "pouet", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "hello"), "pouet") == 0);
	shenv_shvars_set(env, "hello", "", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "hello"), "") == 0);
	shenv_shvars_set(env, "hello", "=======POUET==POUET=POUET==", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "hello"), "=======POUET==POUET=POUET==") == 0);
	mt_assert(shenv_shvars_get_value(env, "not_found") == NULL);
	shenv_del(env);
}

static void	test_clone(t_test *test)
{
	(void)test;
	t_shenv		*env;
	t_shenv		*clone;

	env = shenv_new();
	shenv_shvars_set(env, "quiche", "lorraine", NULL);
	clone = shenv_clone(env);
	shenv_unsetenv(env, "quiche");
	shenv_shvars_set(env, "tarte", "aupomme", NULL);
	mt_assert(twl_strcmp(shenv_shvars_get_value(clone, "quiche"), "lorraine") == 0);
	mt_assert(shenv_shvars_get_value(clone, "tarte") == NULL);
	shenv_del(env);
	shenv_del(clone);
}

static void test_get_paths(t_test *test)
{
	char			*paths;
	char			*fpaths;
	t_shenv	*env;

	(void)test;
	env = shenv_new();
	shenv_init(env);
	fpaths = getenv("PATH");
	char			**path_arr;
	path_arr = shenv_get_paths(env);
	paths = twl_strjoinarr((const char **)path_arr, ":");
	mt_assert(twl_strcmp(fpaths, paths) == 0);
	shenv_del(env);
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
