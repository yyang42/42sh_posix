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
	environment_getenv(env);
	environment_del(env);
	i = 0;
	temp = env->env_vars->head;
	while (environ[i] && temp)
	{
		var = (t_environment_var*)temp->data;
		str = twl_strjoin(var->key, "=");
		str = twl_strjoinfree(str, var->value, 'l');
		printf("%s")
		mt_assert(twl_strcmp(environ[i], str) == 0);
		i++;
		temp = temp->next;
	}
}

void	suite_get_env(t_suite *suite)
{
	SUITE_ADD_TEST(suite, copied_env_is_equal_to_environ);
}
