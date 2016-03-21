#include <project.h>

#include "shenv/shenv.h"
#include "builtin/cmds/builtin_unset.h"
#include "twl_dict.h"
#include "token/tokenizer.h"

static void add_shell_func(t_test *test)
{
	t_shenv		*env;


	env = shenv_new();
	shenv_init(env);
	shenv_add_shell_func(env, "lol", (void *)"echo pouet");
	mt_assert(twl_dict_len(env->shfuncs) == 1);
	shenv_add_shell_func(env, "pouet", (void *)"exec $*");
	shenv_del(env);
}

static void unset_shell_func(t_test *test)
{
	t_shenv		*env;


	env = shenv_new();
	shenv_init(env);
	shenv_add_shell_func(env, "lol", (void *)"echo pouet");
	mt_assert(twl_dict_len(env->shfuncs) == 1);
	builtin_unset_exec(tokenizer_utils_tokenize("unset -f lol"), env);
	mt_assert(twl_dict_len(env->shfuncs) == 0);
	shenv_del(env);
}


void	suite_env_shell_func(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, add_shell_func);
	SUITE_ADD_TEST(suite, unset_shell_func);
}
