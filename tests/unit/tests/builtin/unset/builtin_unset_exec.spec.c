#include <project.h>

#include "shenv/shenv.h"
#include "builtin/cmds/builtin_unset.h"
#include "builtin/cmds/builtin_export.h"
#include "token/tokenizer.h"

static void 	unset_var(t_test *test)
{
	t_shenv		*env;
	int					i;
	int					j;

	(void)test;
	env = shenv_new();
	shenv_init(env);
	builtin_export_exec(tokenizer_tokenize("export HAHA=pouet"), env);
	i = twl_lst_len(env->shvars);
	builtin_unset_exec(tokenizer_tokenize("unset HAHA"), env);
	j = twl_lst_len(env->shvars);
	mt_assert((i - j) == 1);
	shenv_del(env);
}

static void 	unset_func(t_test *test)
{
	t_shenv		*env;
	int					i;
	int					j;

	(void)test;
	env = shenv_new();
	shenv_init(env);
	shenv_add_shell_func(env,"LOL", (void *)"echo pouet");
	i = twl_dict_len(env->shell_func);
	builtin_unset_exec(tokenizer_tokenize("unset LOL"), env);
	j = twl_dict_len(env->shell_func);
	mt_assert((i - j) == 1);
	shenv_del(env);
}

static void 	unset_var_not_func(t_test *test)
{
	t_shenv		*env;
	int					i;
	int					j;
	int					k;
	int					l;

	(void)test;
	env = shenv_new();
	shenv_init(env);
	builtin_export_exec(tokenizer_tokenize("export LOL=pouet"), env);
	shenv_add_shell_func(env,"LOL", (void *)"echo pouet");
	i = twl_dict_len(env->shell_func);
	k = twl_lst_len(env->shvars);
	builtin_unset_exec(tokenizer_tokenize("unset LOL"), env);
	j = twl_dict_len(env->shell_func);
	l = twl_lst_len(env->shvars);
	mt_assert((i - j) == 0);
	mt_assert((k - l) == 1);
	shenv_del(env);
}

static void 	unset_both(t_test *test)
{
	t_shenv		*env;
	int					i;
	int					j;
	int					k;
	int					l;

	(void)test;
	env = shenv_new();
	shenv_init(env);
	builtin_export_exec(tokenizer_tokenize("export LOL=pouet"), env);
	shenv_add_shell_func(env,"LOL", (void *)"echo pouet");
	i = twl_dict_len(env->shell_func);
	k = twl_lst_len(env->shvars);
	builtin_unset_exec(tokenizer_tokenize("unset LOL"), env);
	builtin_unset_exec(tokenizer_tokenize("unset LOL"), env);
	j = twl_dict_len(env->shell_func);
	l = twl_lst_len(env->shvars);
	mt_assert((i - j) == 1);
	mt_assert((k - l) == 1);
	shenv_del(env);
}

void            suite_builtin_unset_exec(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, unset_var);
	SUITE_ADD_TEST(suite, unset_func);
	SUITE_ADD_TEST(suite, unset_var_not_func);
	SUITE_ADD_TEST(suite, unset_both);
}
