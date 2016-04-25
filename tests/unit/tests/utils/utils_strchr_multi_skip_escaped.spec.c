#include <project.h>

#include "utils.h"

char	*g_null_utils_strchr_multi_skip = NULL;

# define mt_test_utils_strchr_multi_skip_escaped(test_name, input, needles, expected, debug) \
	static void test_name(t_test *test) \
	{ \
		char			*actual; \
		actual = utils_strchr_multi_skip_escaped(input, needles); \
		if (debug) \
		{ \
			printf("==== case : %s\n", input); \
			printf("needles   {%s}\n", needles); \
			printf("actual    {%s}\n", actual); \
			printf("expected  {%s}\n", (char *)expected); \
		} \
		if (actual) \
			{ mt_assert(strcmp(actual, expected) == 0); } \
		else \
			{ mt_assert(actual == expected); } \
	}

mt_test_utils_strchr_multi_skip_escaped(test1, "abc", "b", "bc", false);
mt_test_utils_strchr_multi_skip_escaped(test2, "abcbd", "b", "bcbd", false);
mt_test_utils_strchr_multi_skip_escaped(test3, "a\\bcbd", "b", "bd", false);
mt_test_utils_strchr_multi_skip_escaped(test4, "a\\bcbd", "bc", "cbd", false);
mt_test_utils_strchr_multi_skip_escaped(test5, "", "bc", g_null_utils_strchr_multi_skip, false);
mt_test_utils_strchr_multi_skip_escaped(test6, "\\", "bc", g_null_utils_strchr_multi_skip, false);
mt_test_utils_strchr_multi_skip_escaped(test7, "\\b", "bc", g_null_utils_strchr_multi_skip, false);
mt_test_utils_strchr_multi_skip_escaped(test8, "\\\\", "bc", g_null_utils_strchr_multi_skip, false);
mt_test_utils_strchr_multi_skip_escaped(test9, "bc", "", g_null_utils_strchr_multi_skip, false);

void	suite_utils_strchr_multi_skip_escaped(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test4);
	SUITE_ADD_TEST(suite, test5);
	SUITE_ADD_TEST(suite, test6);
	SUITE_ADD_TEST(suite, test7);
	SUITE_ADD_TEST(suite, test8);
	SUITE_ADD_TEST(suite, test9);
}
