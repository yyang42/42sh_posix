#include <project.h>

#include "environment.h"
#include "expan/expan_exec.h"
#include "builtin/builtin_set.h"
#include "token/tokenizer.h"

static void simple_test(t_test *test)
{
	t_shenv	*env;
	char			*ret;

	(void)test;
	env = environment_new();
	environment_init(env);
	builtin_set_exec(tokenizer_tokenize("set lol pouet"), env);
	ret = test_params_sharp(env);
	mt_assert(twl_strcmp(ret,"2") == 0);
	free(ret);
	builtin_set_exec(tokenizer_tokenize("set lol"), env);
	ret = test_params_sharp(env);
	mt_assert(twl_strcmp(ret,"1") == 0);
	environment_del(env);
	free(ret);
}

void	suite_params_sharp(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_test);
}
