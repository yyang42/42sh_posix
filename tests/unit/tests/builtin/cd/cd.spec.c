#include <project.h>

#include "env.h"
#include "environment.h"
#include <stdlib.h>
#include <string.h>
#include "twl_stdio.h"
#include "cd.h"
#include <unistd.h>

static void test_cd(t_test *test)
{
	(void)test;
	char test_pwd[2048];
	char pwd[2048];
	char oldpwd[2048];
	t_environment		*env;

	env = environment_new();
	environment_init(env);
	getcwd(test_pwd, 2048);
	cd_with_env("cd", env);
	mt_assert(twl_strcmp(environment_getenv_value(env, "HOME"), environment_getenv_value(env, "PWD")) == 0);
	getcwd(oldpwd, 2048);
	cd_with_env("cd /bin", env);
	getcwd(pwd, 2048);
	mt_assert(twl_strcmp(oldpwd, environment_getenv_value(env, "OLDPWD")) == 0);
	mt_assert(twl_strcmp(pwd, environment_getenv_value(env, "PWD")) == 0);
	cd_with_env("cd -", env);
	mt_assert(twl_strcmp(pwd, environment_getenv_value(env, "OLDPWD")) == 0);
	cd_with_env("cd ././../../../../../../", env);
	mt_assert(twl_strcmp(environment_getenv_value(env, "PWD"), "/") == 0);
	environment_del(env);
}

void	suite_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_cd);
}
