#include <project.h>
#include "pattern_matching/pattern.h"

#define mt_test_pattern_getpattern(test_name, input, nl, nd, exp, debug)	\
static void test_## test_name(t_test *test)									\
{																			\
	t_pattern		*pat = pattern_new(input);								\
	t_lst			*lst = pattern_get_pattern(pat, nl);					\
	t_pattern_data	*data = twl_lst_get(lst, nd);							\
	char			*actual = data->split;									\
	if (debug)																\
	{																		\
		printf("=== case %s - %i - %i\n", input, nl, nd);					\
		printf("actual   {%s}\n", actual);									\
		printf("expected {%s}\n", exp);										\
	}																		\
	mt_assert(strcmp(actual, exp) == 0);									\
	pattern_del(pat);														\
}

mt_test_pattern_getpattern(num1, "/usr/bin/ls", 0, 0, "usr", false);
mt_test_pattern_getpattern(num2, "/usr/bin/ls", 1, 0, "bin", false);
mt_test_pattern_getpattern(num3, "/usr/bin/ls", 2, 0, "ls", false);
mt_test_pattern_getpattern(num4, "tests/unit/", 0, 0, "tests", false);
mt_test_pattern_getpattern(num5, "tests/unit/", 1, 0, "unit", false);
mt_test_pattern_getpattern(num6, "~/.brew/bin", 0, 0, "~", false);
mt_test_pattern_getpattern(num7, "~/.brew/bin", 1, 0, ".brew", false);
mt_test_pattern_getpattern(num8, "~/.brew/bin", 2, 0, "bin", false);

void		suite_pattern_get_pattern_simple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
}
