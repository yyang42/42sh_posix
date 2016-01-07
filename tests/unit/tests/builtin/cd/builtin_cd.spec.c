#include <project.h>

#include "env.h"
#include "environment.h"
#include <stdlib.h>
#include <string.h>
#include "twl_stdio.h"
#include "cd.h"
#include <unistd.h>

static void test_cd_without_args(t_test *test)
{
	t_environment		*env;

	env = environment_new();
	environment_init(env);

	cd("cd", env);
	mt_assert(twl_strcmp(environment_getenv_value(env, "HOME"), environment_getenv_value(env, "PWD")) == 0);
	environment_del(env);
}

static void test_cd_old_pwd(t_test *test)
{
	t_environment		*env;
	char oldpwd[2048];
	char pwd[2048];

	(void)test;
	env = environment_new();
	environment_init(env);
	cd("cd", env);
	getcwd(oldpwd, 2048);
	cd("cd /bin", env);
	getcwd(pwd, 2048);
	mt_assert(twl_strcmp(oldpwd, environment_getenv_value(env, "OLDPWD")) == 0);
	mt_assert(twl_strcmp(pwd, environment_getenv_value(env, "PWD")) == 0);
	cd("cd -", env);
	mt_assert(twl_strcmp(oldpwd, environment_getenv_value(env, "PWD")) == 0);
	mt_assert(twl_strcmp(pwd, environment_getenv_value(env, "OLDPWD")) == 0);
	environment_del(env);
}
static void test_cd_with_dots(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	cd("cd /bin", env);
	cd("cd ././../../../../../../../../../../", env);
	mt_assert(twl_strcmp(environment_getenv_value(env, "PWD"), "/") == 0);
	environment_del(env);
}

void	suite_builtin_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_cd_without_args);
	SUITE_ADD_TEST(suite, test_cd_old_pwd);
	SUITE_ADD_TEST(suite, test_cd_with_dots);
}
