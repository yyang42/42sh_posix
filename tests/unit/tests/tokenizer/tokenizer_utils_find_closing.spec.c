#include <project.h>

#include "tokenizer.h"

# define mt_test_utils_find_closing(test_name, input, open, close, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char			*closing; \
		closing = tokenizer_utils_find_closing(input, open, close); \
		if (debug) \
		{ \
			printf("closing %s\n", closing); \
		} \
		mt_assert(strcmp(closing, expected) == 0); \
	}

# define mt_test_utils_find_closing_equal(test_name, input, open, close, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char			*closing; \
		closing = tokenizer_utils_find_closing(input, open, close); \
		if (debug) \
		{ \
			printf("found {%s}\n", closing); \
		} \
		mt_assert(closing == expected); \
	}

mt_test_utils_find_closing(num1, "$(123) bbb",      "$(", ")", " bbb", 		false);
mt_test_utils_find_closing(num2, "'abc'12",         "'",  "'", "12", 	 	false);
mt_test_utils_find_closing(num3, "\"abc\"12",       "\"", "\"", "12", 	 	false);
mt_test_utils_find_closing(num4, "(a(b)c)d", 		"(",  ")", "d", 	 	false);
mt_test_utils_find_closing(num5, "$(a$(b)c)123$()", "$(", ")", "123$()", 	false);
mt_test_utils_find_closing(num6, "$(123)$($(",      "$(", ")", "$($(", 		false);
mt_test_utils_find_closing(num7, "`aa`bb",          "`",  "`", "bb", 		false);
mt_test_utils_find_closing(num8, "`1\\`2`3",        "`",  "`", "3", 		false);
mt_test_utils_find_closing(num9, "$(a\\$(b)c", 		"$(", ")", "c", 	 	false);
mt_test_utils_find_closing(num10,"$(a$\\(b)c", 		"$(", ")", "c", 	 	false);
mt_test_utils_find_closing(num11,"$()", 		    "$(", ")", "", 	 		false);
mt_test_utils_find_closing(num12,"$($($($())))abc", "$(", ")", "abc", 	 	false);
mt_test_utils_find_closing(num13,"$($($($(echo a))))abc", "$(", ")", "abc", false);

mt_test_utils_find_closing_equal(equal1, "abc$(123) bbb", "$(", ")", NULL, false);
mt_test_utils_find_closing_equal(equal2, "$(123 bbb",     "$(", ")", NULL, false);
mt_test_utils_find_closing_equal(equal3, ")))",           "$(", ")", NULL, false);

void	suite_tokenizer_utils_find_closing(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_equal1);
	SUITE_ADD_TEST(suite, test_equal2);
	SUITE_ADD_TEST(suite, test_equal3);
}
