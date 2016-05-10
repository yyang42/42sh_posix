#include <project.h>

#include "shenv/shenv.h"
#include "builtin/cmds/builtin_set.h"
#include "builtin/cmds/builtin_export.h"
#include "token/tokenizer.h"

static void	 simple_test(t_test *test)
{
	t_shenv		*env;
	int			i;
	int			j;
	t_lst		*tokens;

	env = shenv_new();
	shenv_init(env);
	i = twl_lst_len(env->shenv_shvars);
	tokens = tokenizer_utils_tokenize("export POPO=PAPA");
	builtin_export_exec(tokens, env);
	token_mgr_del(tokens);
	j = twl_lst_len(env->shenv_shvars);
	mt_assert((j - i) == 1);
	tokens = tokenizer_utils_tokenize("export PIPI=POPO");
	builtin_export_exec(tokens, env);
	token_mgr_del(tokens);
	i = twl_lst_len(env->shenv_shvars);
	mt_assert((i - j) == 1);
	shenv_del(env);
}

static void	 value_is_empty(t_test *test)
{
	t_shenv		*env;
	int			i;
	int			j;
	t_lst		*tokens;

	env = shenv_new();
	shenv_init(env);
	i = twl_lst_len(env->shenv_shvars);
	tokens = tokenizer_utils_tokenize("export HOHO=");
	builtin_export_exec(tokens, env);
	token_mgr_del(tokens);
	j = twl_lst_len(env->shenv_shvars);
	mt_assert((j - i) == 1);
	shenv_del(env);
}

static void	 value_is_null(t_test *test)
{
	t_shenv		*env;
	int			i;
	int			j;
	t_lst		*tokens;

	env = shenv_new();
	shenv_init(env);
	i = twl_lst_len(env->shenv_shvars);
	tokens = tokenizer_utils_tokenize("export POUET");
	builtin_export_exec(tokens, env);
	token_mgr_del(tokens);
	j = twl_lst_len(env->shenv_shvars);
	mt_assert((j - i) == 1);
	shenv_del(env);
}

static void	 key_already_exists(t_test *test)
{
	t_shenv		*env;
	int			i;
	int			j;
	t_lst		*tokens;

	env = shenv_new();
	shenv_init(env);
	i = twl_lst_len(env->shenv_shvars);
	tokens = tokenizer_utils_tokenize("export HOME=/tmp");
	builtin_export_exec(tokens, env);
	token_mgr_del(tokens);
	j = twl_lst_len(env->shenv_shvars);
	mt_assert(twl_strequ(shenv_shvars_get_value(env, "HOME"), "/tmp"));
	mt_assert((j - i) == 0);
	tokens = tokenizer_utils_tokenize("export HOME=/");
	builtin_export_exec(tokens, env);
	token_mgr_del(tokens);
	mt_assert(twl_strequ(shenv_shvars_get_value(env, "HOME"), "/"));
	j = twl_lst_len(env->shenv_shvars);
	mt_assert((j - i) == 0);
	shenv_del(env);
}

void			suite_builtin_export_exec(t_suite *suite)
{

	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, value_is_empty);
	SUITE_ADD_TEST(suite, value_is_null);
	SUITE_ADD_TEST(suite, key_already_exists);
}
