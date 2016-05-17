#include <project.h>

#include "utils.h"

# define mt_test_utils_str_has_line_continuation(test_name, input, expected, debug) \
	static void test_name(t_test *test) \
	{ \
		bool			actual; \
		actual = utils_str_has_line_continuation(input); \
		if (debug) \
		{ \
			printf("==== case : %s\n", input); \
			printf("actual    {%d}\n", actual); \
			printf("expected  {%d}\n", expected); \
		} \
		mt_assert(actual == expected); \
	}

mt_test_utils_str_has_line_continuation(test01, "ab", false, false);
mt_test_utils_str_has_line_continuation(test02, "ab\\", true, false);
mt_test_utils_str_has_line_continuation(test03, "ab\\\\", false, false);
mt_test_utils_str_has_line_continuation(test04, "ab\\\\\\", true, false);
mt_test_utils_str_has_line_continuation(test05, "\\", true, false);
mt_test_utils_str_has_line_continuation(test06, "\\\\", false, false);
mt_test_utils_str_has_line_continuation(test07, "", false, false);

void	suite_utils_str_has_line_continuation(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test01);
	SUITE_ADD_TEST(suite, test02);
	SUITE_ADD_TEST(suite, test03);
	SUITE_ADD_TEST(suite, test04);
	SUITE_ADD_TEST(suite, test05);
	SUITE_ADD_TEST(suite, test06);
	SUITE_ADD_TEST(suite, test07);
}
