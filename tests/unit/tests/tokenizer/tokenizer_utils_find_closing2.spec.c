#include <project.h>

#include "tokenizer.h"

# define mt_test_utils_find_closing2(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char			*closing; \
		closing = tokenizer_utils_find_closing2(input); \
		if (debug) \
		{ \
			printf("closing %s\n", closing); \
		} \
		mt_assert(strcmp(closing, expected) == 0); \
	}

# define mt_test_utils_find_closing2_equal(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char			*closing; \
		closing = tokenizer_utils_find_closing2(input); \
		if (debug) \
		{ \
			printf("found {%s}\n", closing); \
		} \
		mt_assert(closing == expected); \
	}

// mt_test_utils_find_closing2(num1, "$(123) bbb", " bbb", 		true);

// mt_test_utils_find_closing2_equal(equal1, "abc$(123) bbb", "$(", ")", NULL, false);

void	suite_tokenizer_utils_find_closing2(t_suite *suite)
{
	// SUITE_ADD_TEST(suite, test_num1);
	// SUITE_ADD_TEST(suite, test_equal1);
	(void)suite;
}
