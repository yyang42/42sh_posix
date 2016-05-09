#include <project.h>

#include "utils.h"

# define mt_test_utils_str_unescape_backslash(test_name, input, expected, debug) \
	static void test_name(t_test *test) \
	{ \
		char			*actual; \
		actual = utils_str_unescape_backslash(input); \
		if (debug) \
		{ \
			printf("==== case : %s\n", input); \
			printf("actual    {%s}\n", actual); \
			printf("expected  {%s}\n", expected); \
		} \
		mt_assert(strcmp(actual, expected) == 0); \
		free(actual); \
	}

mt_test_utils_str_unescape_backslash(test, "ab", "ab", false);
mt_test_utils_str_unescape_backslash(test1, "aa\\bb", "aabb", false);
mt_test_utils_str_unescape_backslash(test2, "aa\\\\bb", "aa\\bb", false);
mt_test_utils_str_unescape_backslash(test3, "\\\0Bonjour les petits amis", "", false);
mt_test_utils_str_unescape_backslash(test4, "\\\\", "\\", false);
mt_test_utils_str_unescape_backslash(test5, "", "", false);
mt_test_utils_str_unescape_backslash(test6, "\\\n", "\n", false);

void	suite_utils_str_unescape_backslash(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test);
	SUITE_ADD_TEST(suite, test1);
	SUITE_ADD_TEST(suite, test2);
	SUITE_ADD_TEST(suite, test3);
	SUITE_ADD_TEST(suite, test4);
	SUITE_ADD_TEST(suite, test5);
	SUITE_ADD_TEST(suite, test6);
}
