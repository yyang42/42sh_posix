#include <project.h>

#include "openclose_matcher.h"

# define mt_test_openclose(test_name, input, expected, debug, check_equal) \
	static void test_## test_name(t_test *test) \
	{ \
		t_openclose_matcher		*matcher; \
		char					*match; \
		matcher = openclose_matcher_new(); \
		openclose_matcher_add(matcher, "$(", ")"); \
		openclose_matcher_add(matcher, "${", "}"); \
		openclose_matcher_add(matcher, "'", "'"); \
		openclose_matcher_print(matcher); \
		match = openclose_matcher_find_matching(matcher, input); \
		if (debug) \
			printf("match %s\n", match); \
		if (check_equal) \
		{ \
			mt_assert(match == expected); \
		} \
		else \
		{ \
			mt_assert(strcmp(match, expected) == 0); \
		} \
		openclose_matcher_del(matcher); \
	}

mt_test_openclose(num1, "$(123)abc", 		"abc", true, false);
mt_test_openclose(num2, "$(a$(ab)b)abc", 	"abc", true, false);
mt_test_openclose(num3, "$(a${ab}b)abc", 	"abc", true, false);
mt_test_openclose(num4, "'$(ab)'123", 	    "123", true, false);
mt_test_openclose(num5, "'$('ab')'123",     "123", true, false);

mt_test_openclose(equal1, "$(abc", 			NULL,  true, true);

void	suite_openclose_matcher_find_matching(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_equal1);
}
