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
	t_environment		*env;
	// char				*oldpwd;

	env = environment_new();
	environment_init(env);
	twl_printf("PATH1 =%s\n", environment_getenv_value(env, "PWD"));
	cd_with_env("cd /nfs/zfs-student-2/users/atamano/POUET/", env);
	twl_printf("PATH2 =%s\n", environment_getenv_value(env, "PWD"));
	cd_with_env("cd -P lol", env);
	twl_printf("PATH3 =%s\n", environment_getenv_value(env, "PWD"));
}

void	suite_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_cd);
}
