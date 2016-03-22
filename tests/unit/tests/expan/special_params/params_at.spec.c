#include <project.h>

#include "shenv/shenv.h"
#include "builtin/cmds/builtin_set.h"
#include "expan/expan_exec.h"
#include "token/tokenizer.h"

static void simple_test(t_test *test)
{
	char			*ret;
	t_shenv	*env;


	env = shenv_new();
	shenv_init(env);
	ret = test_params_at(env);
	mt_assert(twl_strcmp(ret,"") == 0);
	free(ret);
	builtin_set_exec(tokenizer_utils_tokenize("set lol"), env);
	ret = test_params_at(env);
	mt_assert(twl_strcmp(ret,"lol") == 0);
	free(ret);
	builtin_set_exec(tokenizer_utils_tokenize("set lol pouet"), env);
	ret = test_params_at(env);
	mt_assert(twl_strcmp(ret,"lol pouet") == 0);
	free(ret);
	shenv_del(env);
}

void	suite_params_at(t_suite *suite)
{

	SUITE_ADD_TEST(suite, simple_test);
}
