#include <project.h>

#include "environment.h"
#include "set.h"
#include "xopt.h"
#include <stdlib.h>

char			**make_array()
{
	int i;
	char **arr;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * 2);
	while (i < 1)
	{
		arr[i] = strdup("lol");
		i++;
	}
	arr[1] = NULL;
	return (arr);
}

static void 	test_set_flag(t_test *test)
{
	t_environment		*env;
	t_xopt				*xopt;
	char				*opts;

	(void)test;
	xopt_init(xopt_singleton(), make_array());
	env = environment_new();
	environment_init_env(env);
	set("set -x -a -b");
	xopt = xopt_singleton();
	opts = xopt_concat_opts(xopt);
	mt_assert(twl_strcmp(opts, "xab") == 0);
	environment_del(env);
	xopt_del(xopt_singleton());
}

static void test_unset_flag(t_test *test)
{
	t_environment		*env;
	t_xopt				*xopt;
	char				*opts;

	(void)test;
	xopt_init(xopt_singleton(), make_array());
	env = environment_new();
	environment_init_env(env);
	set("set -x -a -b");
	set("set +x");
	xopt = xopt_singleton();
	opts = xopt_concat_opts(xopt);
	mt_assert(twl_strcmp(opts, "ab") == 0);
	set("set +b");
	opts = xopt_concat_opts(xopt);
	mt_assert(twl_strcmp(opts, "a") == 0);
	set("set +a");
	opts = xopt_concat_opts(xopt);
	mt_assert(twl_strcmp(opts, "") == 0);
	environment_del(env);
	xopt_del(xopt_singleton());
}

static void 	test_o_positive(t_test *test)
{
	t_environment		*env;
	int		out;
	int		p[2];
	int		fd;

	(void)test;
	xopt_init(xopt_singleton(), make_array());
	env = environment_new();
	environment_init_env(env);
	set("set -a");
	set("set -e");
	set("set -f");
	set("set +o");
	environment_del(env);
	xopt_del(xopt_singleton());
}

static void 	test_o_negative(t_test *test)
{
	t_environment		*env;

	(void)test;
	xopt_init(xopt_singleton(), make_array());
	env = environment_new();
	environment_init_env(env);
	set("set -a");
	set("set -e");
	set("set -f");
	set("set -o");
	environment_del(env);
	xopt_del(xopt_singleton());
}

void			suite_set(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_set_flag);
	SUITE_ADD_TEST(suite, test_unset_flag);
	SUITE_ADD_TEST(suite, test_o_positive);
	SUITE_ADD_TEST(suite, test_o_negative);
}
