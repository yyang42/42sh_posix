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

	env = shenv_new();
	shenv_init(env);

	builtin_cd_exec(tokenizer_utils_tokenize("cd"), env);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "HOME"), shenv_shvars_get_value(env, "PWD")) == 0);
	shenv_del(env);
}

static void test_cd_old_pwd(t_test *test)
{
	t_shenv		*env;
	char oldpwd[2048];
	char pwd[2048];

	(void)test;
	env = shenv_new();
	shenv_init(env);
	builtin_cd_exec(tokenizer_utils_tokenize("cd"), env);
	getcwd(oldpwd, 2048);
	builtin_cd_exec(tokenizer_utils_tokenize("cd /bin"), env);
	getcwd(pwd, 2048);
	mt_assert(twl_strcmp(oldpwd, shenv_shvars_get_value(env, "OLDPWD")) == 0);
	mt_assert(twl_strcmp(pwd, shenv_shvars_get_value(env, "PWD")) == 0);
	builtin_cd_exec(tokenizer_utils_tokenize("cd -"), env);
	mt_assert(twl_strcmp(oldpwd, shenv_shvars_get_value(env, "PWD")) == 0);
	mt_assert(twl_strcmp(pwd, shenv_shvars_get_value(env, "OLDPWD")) == 0);
	shenv_del(env);
}
static void test_cd_with_dots(t_test *test)
{
	t_shenv		*env;

	(void)test;
	env = shenv_new();
	shenv_init(env);
	builtin_cd_exec(tokenizer_utils_tokenize("cd /bin"), env);
	builtin_cd_exec(tokenizer_utils_tokenize("cd ././../../../../../../../../../../"), env);
	mt_assert(twl_strcmp(shenv_shvars_get_value(env, "PWD"), "/") == 0);
	shenv_del(env);
}

void	suite_builtin_cd(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_cd_without_args);
	SUITE_ADD_TEST(suite, test_cd_old_pwd);
	SUITE_ADD_TEST(suite, test_cd_with_dots);
}
