#include <project.h>

#include "builtin/cmds/builtin_cd.h"

# define mt_test_logpath(test_name, path, expected, debug)	\
static void test_## test_name(t_test *test)					\
{															\
	char	*actual = builtin_cd_logpath(path);				\
	if (debug)												\
	{														\
		printf("case ======\n");							\
		printf("path     : %s\n", path);					\
		printf("actual   : %s\n", actual);					\
		printf("expected : %s\n", expected);				\
	}														\
	mt_assert(strcmp(actual, expected) == 0);				\
	free(actual);											\
}

mt_test_logpath(num01, "/../../", "/", false);
mt_test_logpath(num02, "//../../", "//", false);
mt_test_logpath(num03, "/aa//./../Bonjour/bb//bb//./../bb/../../les/.../.../.././.././amis", "/Bonjour/les/amis", false);
mt_test_logpath(num04, "//aa//./../Bonjour/bb//bb//./../bb/../../les/.../.../.././.././amis", "//Bonjour/les/amis", false);


void			suite_logpath(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
}
