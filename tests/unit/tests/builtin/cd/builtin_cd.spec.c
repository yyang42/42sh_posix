#include <project.h>

#include "builtin/cmds/builtin_env.h"
#include "shenv/shenv.h"
#include <stdlib.h>
#include <string.h>
#include "twl_stdio.h"
#include "builtin/cmds/builtin_cd.h"
#include "token/tokenizer.h"
#include <unistd.h>

static void test_cd_without_args(t_test *test)
{
	t_shenv		*env;

	env = environment_new();
	environment_init(env);

	builtin_cd_exec(tokenizer_tokenize("cd"), env);
	mt_assert(twl_strcmp(environment_getenv_value(env, "HOME"), environment_getenv_value(env, "PWD")) == 0);
	environment_del(env);
}

static void test_cd_old_pwd(t_test *test)
{
	t_shenv		*env;
	char oldpwd[2048];
	char pwd[2048];

	(void)test;
	env = environment_new();
	environment_init(env);
	builtin_cd_exec(tokenizer_tokenize("cd"), env);
	getcwd(oldpwd, 2048);
	builtin_cd_exec(tokenizer_tokenize("cd /bin"), env);
	getcwd(pwd, 2048);
	mt_assert(twl_strcmp(oldpwd, environment_getenv_value(env, "OLDPWD")) == 0);
	mt_assert(twl_strcmp(pwd, environment_getenv_value(env, "PWD")) == 0);
	builtin_cd_exec(tokenizer_tokenize("cd -"), env);
	mt_assert(twl_strcmp(oldpwd, environment_getenv_value(env, "PWD")) == 0);
	mt_assert(twl_strcmp(pwd, environment_getenv_value(env, "OLDPWD")) == 0);
	environment_del(env);
}
static void test_cd_with_dots(t_test *test)
{
	t_shenv		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	builtin_cd_exec(tokenizer_tokenize("cd /bin"), env);
	builtin_cd_exec(tokenizer_tokenize("cd ././../../../../../../../../../../"), env);
	mt_assert(twl_strcmp(environment_getenv_value(env, "PWD"), "/") == 0);
	environment_del(env);
}

void	suite_builtin_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_cd_without_args);
	SUITE_ADD_TEST(suite, test_cd_old_pwd);
	SUITE_ADD_TEST(suite, test_cd_with_dots);
}
