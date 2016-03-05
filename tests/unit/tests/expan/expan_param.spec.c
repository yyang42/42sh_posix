#include <project.h>

#include "basics.h"
#include "expan/expan_mgr.h"
#include "expan/expan_param.h"
#include "expan/expan_exec.h"
#include "expan/expan_token_origin.h"
#include "shenv/shenv.h"
#include "builtin/cmds/builtin_set.h"
#include "builtin/cmds/builtin_export.h"
#include "token/tokenizer.h"

static void simple_pos_param(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_set_exec(tokenizer_tokenize("set lol pouet"), env);
	str = twl_strdup("$1");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	str = twl_strdup("$2");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"pouet") == 0);
	twl_strdel(&str);
}


static void simple_pos_param_sub(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_export_exec(tokenizer_tokenize("set lol pouet"), env);
	str = twl_strdup("$1");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	str = twl_strdup("$2");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"pouet") == 0);
	twl_strdel(&str);
}

static void simple_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset LOL"), env);
	builtin_export_exec(tokenizer_tokenize("export LOL=POUET"), env);
	str = twl_strdup("$LOL");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"POUET") == 0);
	twl_strdel(&str);
	str = twl_strdup("${LOL}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"POUET") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset LOL"), env);
}

static void colon_hyphen_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset HAHA"), env);
	str = twl_strdup("${HAHA:-ls}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"ls") == 0);
	twl_strdel(&str);
	builtin_export_exec(tokenizer_tokenize("export HAHA=HOHO"), env);
	str = twl_strdup("${HAHA:-ls}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"HOHO") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset HAHA"), env);
}

static void colon_hyphen_param_str_quoted(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset HAHA"), env);
	str = twl_strdup("${HAHA:-l\"}\"s}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"l}s") == 0);
	twl_strdel(&str);
	str = twl_strdup("${HAHA:-l\'}\'s}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"l}s") == 0);
	twl_strdel(&str);
	str = twl_strdup("${HAHA:-l\\}s}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"l}s") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset HAHA"), env);
}

static void hyphen_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset HAHA"), env);
	builtin_export_exec(tokenizer_tokenize("export HAHA=HOHO"), env);
	str = twl_strdup("${HAHA-ls}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"HOHO") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset HAHA"), env);
	str = twl_strdup("${HAHA-HOHO}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"HOHO") == 0);
	twl_strdel(&str);
	builtin_export_exec(tokenizer_tokenize("export HAHA"), env);
	str = twl_strdup("${HAHA-HOHO}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
}

static void colon_equal_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	str = twl_strdup("${X:=abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	str = twl_strdup("${X:=lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
}

static void equal_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	str = twl_strdup("${X=abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	str = twl_strdup("${X=lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"abc") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	builtin_export_exec(tokenizer_tokenize("export X"), env);
	str = twl_strdup("${X=abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(environment_getenv_value(env, "X"),"") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
}

static void colon_question_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	str = twl_strdup("${X:?abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	builtin_export_exec(tokenizer_tokenize("export X=lol"), env);
	str = twl_strdup("${X:?lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
}

static void question_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	str = twl_strdup("${X?abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	builtin_export_exec(tokenizer_tokenize("export X=lol"), env);
	str = twl_strdup("${X?lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	builtin_export_exec(tokenizer_tokenize("export X"), env);
	str = twl_strdup("${X?lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
}

static void colon_plus_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	str = twl_strdup("${X:+abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	builtin_export_exec(tokenizer_tokenize("export X=lol"), env);
	str = twl_strdup("${X:+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	builtin_export_exec(tokenizer_tokenize("export X"), env);
	str = twl_strdup("${X:+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
}

static void plus_param_str(t_test *test)
{
	t_shenv	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	str = twl_strdup("${X+abc}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"") == 0);
	twl_strdel(&str);
	builtin_export_exec(tokenizer_tokenize("export X=lol"), env);
	str = twl_strdup("${X+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
	builtin_export_exec(tokenizer_tokenize("export X"), env);
	str = twl_strdup("${X+lol}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	builtin_unset_exec(tokenizer_tokenize("unset X"), env);
}

void	suite_expan_param(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_pos_param);
	SUITE_ADD_TEST(suite, simple_pos_param_sub);
	SUITE_ADD_TEST(suite, simple_param_str);
	SUITE_ADD_TEST(suite, colon_hyphen_param_str);
	SUITE_ADD_TEST(suite, colon_hyphen_param_str_quoted);
	SUITE_ADD_TEST(suite, hyphen_param_str);
	SUITE_ADD_TEST(suite, colon_equal_param_str);
	SUITE_ADD_TEST(suite, equal_param_str);
	SUITE_ADD_TEST(suite, colon_question_param_str);
	SUITE_ADD_TEST(suite, question_param_str);
	SUITE_ADD_TEST(suite, colon_plus_param_str);
	SUITE_ADD_TEST(suite, plus_param_str);
}
