#include <project.h>

#include "token/token_utils.h"

# define mt_test_token_utils_is_valid_name(test_name, input, expected_bool) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(token_utils_is_valid_name(input) == expected_bool); \
	}

mt_test_token_utils_is_valid_name(num1, "abc",   true);
mt_test_token_utils_is_valid_name(num2, "1abc",  false);
mt_test_token_utils_is_valid_name(num3, "123",   false);
mt_test_token_utils_is_valid_name(num4, "",      false);
mt_test_token_utils_is_valid_name(num5, "#",     false);
mt_test_token_utils_is_valid_name(num6, "a123",  true);
mt_test_token_utils_is_valid_name(num7, "_",     true);
mt_test_token_utils_is_valid_name(num8, "___",     true);
mt_test_token_utils_is_valid_name(num9, "_123",     true);
mt_test_token_utils_is_valid_name(num10, "123_",     false);
mt_test_token_utils_is_valid_name(num11, "1_",     false);

void	suite_token_utils_is_valid_name(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_num9);
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
}
