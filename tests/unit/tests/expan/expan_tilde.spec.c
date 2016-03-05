#include <project.h>

#include "basics.h"
#include "shenv/shenv.h"
#include "builtin/cmds/builtin_export.h"
#include "expan/expan_tilde.h"

static void simple_tilde(t_test *test)
{
	t_shenv	*env;
	char		 	*res;
	char			*home;
	char			*token;
	char			*suffix;

	(void)test;
	env = shenv_singleton();
	res = NULL;
	token = twl_strdup("~");
	suffix = twl_strdup("");
	expan_tilde_do(&res, token, suffix);
	home = shenv_getenv_value(env, "HOME");
	mt_assert(twl_strcmp(home,res) == 0);
	twl_strdel(&res);
	twl_strdel(&token);
	twl_strdel(&suffix);
}

// static void tilde_with_known_suffix(t_test *test)
// {
// 	t_shenv	*env;
// 	char		 	*res;
// 	char			*token;
// 	char			*suffix;
//
// 	(void)test;
// 	env = shenv_singleton();
// 	res = NULL;
// 	token = twl_strdup("~");
// 	suffix = twl_strdup("root");
// 	expan_tilde_do(&res, token, suffix);
// 	mt_assert(twl_strcmp("/var/root",res) == 0);
// 	twl_strdel(&res);
// 	twl_strdel(&token);
// 	twl_strdel(&suffix);
// }

static void tilde_with_unknown_suffix(t_test *test)
{
	//t_shenv	*env;
	char		 	*res;
	char			*token;
	char			*suffix;

	(void)test;
	//env = shenv_singleton();
	res = NULL;
	token = twl_strdup("~");
	suffix = twl_strdup("pouet");
	expan_tilde_do(&res, token, suffix);
	mt_assert(twl_strcmp("~pouet",res) == 0);
	twl_strdel(&res);
	twl_strdel(&token);
	twl_strdel(&suffix);
}

void	suite_expan_tilde(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_tilde);
	// SUITE_ADD_TEST(suite, tilde_with_known_suffix);
	SUITE_ADD_TEST(suite, tilde_with_unknown_suffix);
}
