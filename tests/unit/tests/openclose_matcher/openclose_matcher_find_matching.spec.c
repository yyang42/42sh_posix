#include <project.h>

#include "openclose/openclose_matcher.h"

# define mt_test_openclose(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_openclose_matcher		*matcher; \
		char					*match; \
		matcher = openclose_matcher_new(0); \
		openclose_matcher_add(matcher, "$(", ")"); \
		openclose_matcher_add(matcher, "${", "}"); \
		openclose_matcher_add(matcher, "'", "'"); \
		match = openclose_matcher_find_matching(matcher, input); \
		if (debug) \
		{ \
			openclose_matcher_print(matcher); \
			printf("match %s\n", match); \
		} \
		mt_assert(strcmp(match, expected) == 0); \
		openclose_matcher_del(matcher); \
	}

mt_test_openclose(num1, "$(123)abc", 		"abc", false);
mt_test_openclose(num2, "$(a$(ab)b)abc", 	"abc", false);
mt_test_openclose(num3, "$(a${ab}b)abc", 	"abc", false);
mt_test_openclose(num4, "'$(ab)'123", 	    "123", false);
mt_test_openclose(num5, "'$('ab')'123",     "123", false);
mt_test_openclose(num6, "'$('a$('$()')b')'123", "123", false);
mt_test_openclose(num7, "'$('$('$()')')'",  "", false);
mt_test_openclose(num8, "$()",  			"", false);
mt_test_openclose(num10, "''",  			"", false);
mt_test_openclose(num11, "'$(1${2'3${4${5}6}7'8}9)0'abc$(${$('')})", "abc$(${$('')})", false);

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

}
