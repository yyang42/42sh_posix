#include <project.h>

#include "openclose/openclose_matcher.h"

# define mt_test_openclose(test_name, input, expected, flags, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_openclose_matcher		*matcher; \
		char					*match; \
		matcher = openclose_matcher_new(flags); \
		openclose_matcher_add(matcher, "$(", ")"); \
		openclose_matcher_add(matcher, "${", "}"); \
		openclose_matcher_add(matcher, "'", "'"); \
		openclose_matcher_add(matcher, "\"", "\""); \
		match = openclose_matcher_find_matching(matcher, input); \
		if (debug) \
		{ \
			openclose_matcher_print(matcher); \
			printf("match %s\n", match); \
		} \
		mt_assert(strcmp(match, expected) == 0); \
		openclose_matcher_del(matcher); \
	}

mt_test_openclose(num1, "$('$(')abc",  			"abc", OC_MATCHER_JUMP_SINGLE_QUOTE, false);
mt_test_openclose(num2, "$('${{{{{($(')abc",    "abc", OC_MATCHER_JUMP_SINGLE_QUOTE, false);
mt_test_openclose(num3, "$(\"'\")abc",          "abc", OC_MATCHER_JUMP_SINGLE_QUOTE, true);

void	suite_openclose_matcher_find_matching_flags(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
}
