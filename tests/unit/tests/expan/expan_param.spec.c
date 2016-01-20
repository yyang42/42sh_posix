#include <project.h>

#include "basics.h"
#include "ast/expan/ast_expan_mgr.h"
#include "ast/expan/ast_expan_param.h"
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_token_origin.h"
#include "environment.h"
#include "set.h"
#include "export.h"

static void simple_pos_param_num(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	set("set lol pouet", env);
	str = twl_strdup("$1");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	str = twl_strdup("$2");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"pouet") == 0);
	twl_strdel(&str);
}


static void simple_pos_param_sub_num(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	export("set lol pouet", env);
	str = twl_strdup("$1");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"lol") == 0);
	twl_strdel(&str);
	str = twl_strdup("$2");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"pouet") == 0);
	twl_strdel(&str);
}

static void simple_pos_param_str(t_test *test)
{
	t_environment	*env;
	char			*str;

	(void)test;
	env = environment_singleton();
	export("export LOL=POUET", env);
	str = twl_strdup("$LOL");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"POUET") == 0);
	twl_strdel(&str);
	str = twl_strdup("${LOL}");
	expan_init(&str, SIMPLE_COMMAND_TOKEN);
	mt_assert(twl_strcmp(str,"POUET") == 0);
	twl_strdel(&str);
	unset("unset LOL", env);
}

void	suite_expan_param(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_pos_param_num);
	SUITE_ADD_TEST(suite, simple_pos_param_sub_num);
	SUITE_ADD_TEST(suite, simple_pos_param_str);
}
