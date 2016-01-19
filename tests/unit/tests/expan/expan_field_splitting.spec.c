#include <project.h>

#include "basics.h"
#include "environment.h"
#include "export.h"
#include "ast/expan/ast_expan_field_splitting.h"

static void simple_unset_ifs_test(t_test *test)
{
	char *str;

	str = twl_strdup(" \t\n lol \t\n poiuet \t \n   ");
	expan_field_splitting(&str);
	mt_assert(twl_strcmp(str,"lol poiuet") == 0);
	twl_strdel(&str);
}

static void simple_null_ifs_test(t_test *test)
{
	char			*str;
	t_environment	*env;

	env = environment_singleton();
	export("export IFS", env);
	str = twl_strdup(" \t\n lol \t\n poiuet \t \n   ");
	expan_field_splitting(&str);
	mt_assert(twl_strcmp(str," \t\n lol \t\n poiuet \t \n   ") == 0);
	twl_strdel(&str);
}

static void simple_ifs_test(t_test *test)
{
	char			*str;
	t_environment	*env;

	env = environment_singleton();
	export("export IFS=o", env);
	str = twl_strdup("oooolopotorototoooo");
	expan_field_splitting(&str);
	mt_assert(twl_strcmp(str,"    l p t r t t   ") == 0);
	twl_strdel(&str);
}

void	suite_expan_field_splitting(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_unset_ifs_test);
	SUITE_ADD_TEST(suite, simple_null_ifs_test);
	SUITE_ADD_TEST(suite, simple_ifs_test);
}
