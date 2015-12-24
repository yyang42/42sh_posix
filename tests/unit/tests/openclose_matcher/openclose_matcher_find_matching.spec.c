#include <project.h>

#include "openclose_matcher.h"

# define mt_test_openclose(test_name, input, expected, check_equal, debug) \
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
		} \
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

mt_test_openclose(num1, "$(123)abc", 		"abc", false, false);
mt_test_openclose(num2, "$(a$(ab)b)abc", 	"abc", false, false);
mt_test_openclose(num3, "$(a${ab}b)abc", 	"abc", false, false);
mt_test_openclose(num4, "'$(ab)'123", 	    "123", false, false);
mt_test_openclose(num5, "'$('ab')'123",     "123", false, false);
mt_test_openclose(num6, "'$('a$('$()')b')'123", "123", false, false);
mt_test_openclose(num7, "'$('$('$()')')'",  "", false, false);
mt_test_openclose(num8, "$()",  			"", false, false);
mt_test_openclose(num10, "''",  			"", false, false);
mt_test_openclose(num11, "'$(1${2'3${4${5}6}7'8}9)0'abc$(${$('')})", "abc$(${$('')})", false, false);

mt_test_openclose(equal1, "$(abc", 			NULL,  true, false);
mt_test_openclose(equal2, "", 			    NULL,  true, false);
mt_test_openclose(equal3, "'", 			    NULL,  true, false);

void	suite_openclose_matcher_find_matching(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_equal1);
	SUITE_ADD_TEST(suite, test_equal2);
	SUITE_ADD_TEST(suite, test_equal3);
}
