#include <project.h>

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
	environment_init_env(env);
	environment_del(env);
	i = 0;
	temp = env->env_vars->head;
	while (environ[i] != NULL && temp != NULL)
	{
		var = (t_environment_var*)temp->data;
		str = twl_strjoin(var->key, "=");
		str = twl_strjoinfree(str, var->value, 'l');
		mt_assert(twl_strcmp(environ[i], str) == 0);
		i++;
		temp = temp->next;
	}
}

static void test_set_env(t_test *test)
{
	(void)test;
	t_environment		*env;

	env = environment_new();
	environment_init_env(env);
	mt_assert(environment_get_env_value(env, "_key") == NULL);
	environment_setenv(env, "_key=_value");
	mt_assert(twl_strcmp(environment_get_env_value(env, "_key"), "_value") == 0);
	environment_setenv(env, "_key=_new_value");
	printf("AAAA %s\n", environment_get_env_value(env, "_key"));
	mt_assert(twl_strcmp(environment_get_env_value(env, "_key"), "_new_value") == 0);
	// environment_setenv(env, "_key=");
	// mt_assert(twl_strcmp(environment_get_env_value(env, "_key"), "") == 0);
}

void	suite_get_env(t_suite *suite)
{
	SUITE_ADD_TEST(suite, copied_env_is_equal_to_environ);
	SUITE_ADD_TEST(suite, test_set_env);
}
