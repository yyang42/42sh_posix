#include <project.h>

#include "tokenizer.h"

# define mt_test_utils_find_closing_plus(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char			*closing; \
		closing = tokenizer_utils_find_closing_plus(input); \
		if (debug) \
		{ \
			printf("closing %s\n", closing); \
		} \
		mt_assert(strcmp(closing, expected) == 0); \
	}

# define mt_test_utils_find_closing_plus_equal(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char			*closing; \
		closing = tokenizer_utils_find_closing_plus(input); \
		if (debug) \
		{ \
			printf("found {%s}\n", closing); \
		} \
		mt_assert(closing == expected); \
	}

mt_test_utils_find_closing_plus(num1, "$(123)abc",      "abc", 		false);
mt_test_utils_find_closing_plus(num2, "`123`abc",       "abc", 		false);
mt_test_utils_find_closing_plus(num3, "\"123\"abc",     "abc", 		false);
mt_test_utils_find_closing_plus(num4, "'123'abc",       "abc", 		false);

mt_test_utils_find_closing_plus_equal(equal1, "abc$(123) bbb", NULL, false);

void	suite_tokenizer_utils_find_closing_plus(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_equal1);
}
