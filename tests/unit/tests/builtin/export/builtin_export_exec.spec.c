#include <project.h>

#include "shenv/shenv.h"
#include "builtin/cmds/builtin_set.h"
#include "builtin/cmds/builtin_export.h"
#include "token/tokenizer.h"

static void     simple_test(t_test *test)
{
    t_shenv		*env;
	int					i;
	int					j;

    (void)test;
    env = shenv_new();
	shenv_init(env);
	i = twl_lst_len(env->shvars);
	builtin_export_exec(tokenizer_utils_tokenize("export POPO=PAPA"), env);
	j = twl_lst_len(env->shvars);
    mt_assert((j - i) == 1);
	builtin_export_exec(tokenizer_utils_tokenize("export PIPI=POPO"), env);
	i = twl_lst_len(env->shvars);
	mt_assert((i - j) == 1);
	shenv_del(env);
}

static void     value_is_empty(t_test *test)
{
    t_shenv		*env;
	int					i;
	int					j;

    (void)test;
    env = shenv_new();
	shenv_init(env);
	i = twl_lst_len(env->shvars);
	builtin_export_exec(tokenizer_utils_tokenize("export HOHO="), env);
	j = twl_lst_len(env->shvars);
	mt_assert((j - i) == 1);
	shenv_del(env);
}

// static void     value_is_null(t_test *test)
// {
//     t_shenv		*env;
// 	int					i;
// 	int					j;

//     (void)test;
//     env = shenv_new();
// 	shenv_init(env);
// 	i = twl_lst_len(env->shvars);
// 	builtin_export_exec(tokenizer_utils_tokenize("export HUHIAH"), env);
// 	j = twl_lst_len(env->shvars);
// 	mt_assert((j - i) == 1);
// 	shenv_del(env);
// }

static void     key_already_exists(t_test *test)
{
    t_shenv		*env;
	int					i;
	int					j;

    (void)test;
    env = shenv_new();
	shenv_init(env);
	i = twl_lst_len(env->shvars);
	builtin_export_exec(tokenizer_utils_tokenize("export HOME=/tmp"), env);
	j = twl_lst_len(env->shvars);
	mt_assert(!twl_strcmp(shenv_shvars_get_value(env, "HOME"), "/tmp"));
	mt_assert((j - i) == 0);
	builtin_export_exec(tokenizer_utils_tokenize("export HOME=/"), env);
	mt_assert(!twl_strcmp(shenv_shvars_get_value(env, "HOME"), "/"));
	j = twl_lst_len(env->shvars);
	mt_assert((j - i) == 0);
	shenv_del(env);
}

void            suite_builtin_export_exec(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_test);
	SUITE_ADD_TEST(suite, value_is_empty);
	// SUITE_ADD_TEST(suite, value_is_null);
	SUITE_ADD_TEST(suite, key_already_exists);
}
