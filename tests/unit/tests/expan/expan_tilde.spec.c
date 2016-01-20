#include <project.h>

#include "basics.h"
#include "environment.h"
#include "export.h"
#include "ast/expan/ast_expan_tilde.h"

static void simple_tilde(t_test *test)
{
	t_environment	*env;
	char		 	*res;
	char			*home;

	(void)test;
	env = environment_singleton();
	res = NULL;
	expan_tilde_do(&res, twl_strdup("~"), twl_strdup(""));
	home = environment_getenv_value(env, "HOME");
	mt_assert(twl_strcmp(home,res) == 0);
	twl_strdel(&res);
}

static void tilde_with_known_suffix(t_test *test)
{
	t_environment	*env;
	char		 	*res;

	(void)test;
	env = environment_singleton();
	res = NULL;
	expan_tilde_do(&res, twl_strdup("~"), twl_strdup("root"));
	mt_assert(twl_strcmp("/var/root",res) == 0);
	twl_strdel(&res);
}

static void tilde_with_unknown_suffix(t_test *test)
{
	t_environment	*env;
	char		 	*res;

	(void)test;
	env = environment_singleton();
	res = NULL;
	expan_tilde_do(&res, twl_strdup("~"), twl_strdup("pouet"));
	mt_assert(twl_strcmp("~pouet",res) == 0);
	twl_strdel(&res);
}

void	suite_expan_tilde(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_tilde);
	SUITE_ADD_TEST(suite, tilde_with_known_suffix);
	SUITE_ADD_TEST(suite, tilde_with_unknown_suffix);
}
