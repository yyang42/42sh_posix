#include <project.h>
#include "pattern_matching/pattern.h"

#define mt_test_pattern_getpattern(test_name, input, nl, nd, exp, debug)	\
static void test_## test_name(t_test *test)									\
{																			\
	t_pattern		*pat = pattern_new(input);								\
	t_lst			*lst = pattern_get_pattern(pat, nl);					\
	t_pattern_data	*data = twl_lst_get(lst, nd);							\
	char			*actual = data->split;									\
	if (debug)																\
	{																		\
		printf("=== case %s - %i - %i\n", input, nl, nd);					\
		printf("actual   {%s}\n", actual);									\
		printf("expected {%s}\n", exp);										\
	}																		\
	mt_assert(strcmp(actual, exp) == 0);									\
	pattern_del(pat);														\
}

mt_test_pattern_getpattern(num1, "/////u'*'r/////b[[:lower:]]n/////l?", 0, 0, "u*r", false);
mt_test_pattern_getpattern(num2, "/////u*r/////b[[:lower:]]n/////l?", 0, 0, "u", false);
mt_test_pattern_getpattern(num3, "/////u*r/////b[[:lower:]]n/////l?", 0, 1, "*", false);
mt_test_pattern_getpattern(num4, "/////u*r/////b[[:lower:]]n/////l?", 0, 2, "r", false);
mt_test_pattern_getpattern(num5, "/////u*r/////b[[:lower:]]n/////l?", 1, 0, "b", false);
mt_test_pattern_getpattern(num6, "/////u*r/////b[[:lower:]]n/////l?", 1, 1, "[[:lower:]]", false);
mt_test_pattern_getpattern(num7, "/////u*r/////b[[:lower:]]n/////l?", 1, 2, "n", false);
mt_test_pattern_getpattern(num8, "/////u*r/////b[[:lower:]]n/////l?", 2, 0, "l", false);
mt_test_pattern_getpattern(num9, "/////u*r/////b[[:lower:]]n/////l?", 2, 1, "?", false);
mt_test_pattern_getpattern(num10, "*?[a]", 0, 0, "*", false);
mt_test_pattern_getpattern(num11, "*?[a]", 0, 1, "?", false);
mt_test_pattern_getpattern(num12, "*?[a]", 0, 2, "[a]", false);
mt_test_pattern_getpattern(num13, "a[*", 0, 0, "a[", false);
mt_test_pattern_getpattern(num14, "a[*", 0, 1, "*", false);

void		suite_pattern_get_pattern_hardle(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num14);
}
