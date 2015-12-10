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
	char buf[1024];
	t_environment		*env;
	// char				*oldpwd;

	env = environment_new();
	environment_init(env);
	cd("cd");
	twl_bzero(buf, 1024);
	getcwd(buf, 1024);
	mt_assert(twl_strcmp(environment_getenv_value(env, "HOME"), buf) == 0);
	cd("cd /bin/ls");
	mt_assert(twl_strcmp(environment_getenv_value(env, "HOME"), buf) == 0);
	// oldpwd = environment_getenv_value(env, "OLDPWD");
	cd("cd -");
	// mt_assert(twl_strcmp(oldpwd, environment_getenv_value(env, "HOME")) == 0);
	cd("cd /bin");
	getcwd(buf, 1024);
	mt_assert(twl_strcmp(buf, "/bin") == 0);
	cd("cd NOTEXIST");
	mt_assert(twl_strcmp(buf, "/bin") == 0);
}

void	suite_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_cd);
}
