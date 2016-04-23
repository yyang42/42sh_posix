#include <project.h>

#include "openclose/openclose_matcher.h"

# define mt_test_openclose(test_name, input, expected, debug) \
	static void test_name(t_test *test) \
	{ \
		t_openclose_matcher		*matcher; \
		char					*match; \
		matcher = openclose_matcher_new(); \
		openclose_matcher_add(matcher, "$((", "))"); \
		openclose_matcher_add(matcher, "$(", ")"); \
		openclose_matcher_add(matcher, "${", "}"); \
		openclose_matcher_add(matcher, "`", "`"); \
		openclose_matcher_add(matcher, "\"", "\""); \
		openclose_matcher_add(matcher, "\'", "\'"); \
		openclose_matcher_add(matcher, "(", ")"); \
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
mt_test_openclose(num5, "'$('ab')'123",     "ab')'123", false);
mt_test_openclose(num6, "'$('a$('$()')b')'123", "a$('$()')b')'123", false);
mt_test_openclose(num7, "'$('$('$()')')'",  "$('$()')')'", false);
mt_test_openclose(num8, "$()",  			"", false);
mt_test_openclose(num10, "''",  			"", false);
mt_test_openclose(num11, "'$(1${2'3${4${5}6}7'8}9)0'abc$(${$('')})", "3${4${5}6}7'8}9)0'abc$(${$('')})", false);
mt_test_openclose(num12, "\"12\\\"34\"abc", 		"abc", false);
mt_test_openclose(num13, "\"12\\\"\\\\'34\"abc", 		"abc", false);
mt_test_openclose(num14, "$(a\\$(b)c", 		"c", false);
mt_test_openclose(num15, "$(( 2+(1+2)))abc", 		"abc", false);
mt_test_openclose(num16, "$(((2+(1+2))))abc", 		"abc", false);
mt_test_openclose(num17, "$(( (2+(1+2)) ))abc", 		"abc", false);
mt_test_openclose(num18, "$(( ((1)) ))abc", 		"abc", false);
mt_test_openclose(num19, "$('$(')abc",  			"abc", false);
mt_test_openclose(num20, "$('${{{{{($(')abc",    "abc", false);
mt_test_openclose(num21, "$(\"'\")abc",          "abc", false);

void	suite_openclose_matcher_find_matching(t_suite *suite)
{
	SUITE_ADD_TEST(suite, num1);
	SUITE_ADD_TEST(suite, num2);
	SUITE_ADD_TEST(suite, num3);
	SUITE_ADD_TEST(suite, num4);
	SUITE_ADD_TEST(suite, num5);
	SUITE_ADD_TEST(suite, num6);
	SUITE_ADD_TEST(suite, num7);
	SUITE_ADD_TEST(suite, num8);
	SUITE_ADD_TEST(suite, num10);
	SUITE_ADD_TEST(suite, num11);
	SUITE_ADD_TEST(suite, num12);
	SUITE_ADD_TEST(suite, num13);
	SUITE_ADD_TEST(suite, num14);
	SUITE_ADD_TEST(suite, num15);
	SUITE_ADD_TEST(suite, num16);
	SUITE_ADD_TEST(suite, num17);
	SUITE_ADD_TEST(suite, num18);
	SUITE_ADD_TEST(suite, num19);
	SUITE_ADD_TEST(suite, num20);
	SUITE_ADD_TEST(suite, num21);
}
