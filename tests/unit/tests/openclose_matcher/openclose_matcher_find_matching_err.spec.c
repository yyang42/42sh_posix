#include <project.h>

#include "openclose/openclose_matcher.h"

# define mt_test_openclose_err(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_openclose_matcher		*matcher; \
		char					*match; \
		matcher = openclose_matcher_new(); \
		openclose_matcher_add(matcher, "$(", ")"); \
		openclose_matcher_add(matcher, "${", "}"); \
		openclose_matcher_add(matcher, "'", "'"); \
		match = openclose_matcher_find_matching(matcher, input); \
		if (debug) \
		{ \
			openclose_matcher_print(matcher); \
			printf("match %s\n", match); \
			printf("err_msg %s\n", matcher->err_msg); \
		} \
		mt_assert(strcmp(matcher->err_msg, expected) == 0); \
		openclose_matcher_del(matcher); \
	}

mt_test_openclose_err(num1, "$(123", 		"looking for matching `)'", false);
mt_test_openclose_err(num2, "", 		    "nothing to match", false);
mt_test_openclose_err(num3, "'", 		    "looking for matching `''", false);

void	suite_openclose_matcher_find_matching_err(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
}
