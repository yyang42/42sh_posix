#include <project.h>
#include "pattern_matching/pattern_substr.h"

#define mt_test_pattern_getpattern(test_name, input, nb, exp, debug)	\
static void test_## test_name(t_test *test)								\
{																		\
	t_pattern_substr		*pat = pattern_substr_new(input);			\
	pattern_substr_rev(pat);											\
	t_pattern_substr_data	*data = pattern_substr_get_data(pat, nb);	\
	char					*actual = data->piece;						\
	if (debug)															\
	{																	\
		printf("=== case %s - %i\n", input, nb);						\
		printf("actual   {%s}\n", actual);								\
		printf("expected {%s}\n", exp);									\
	}																	\
	mt_assert(strcmp(actual, exp) == 0);								\
	pattern_substr_del(pat);											\
}

mt_test_pattern_getpattern(num1, "a[aze", 0, "eza[a", false);
mt_test_pattern_getpattern(num2, "a[az*e", 0, "e", false);
mt_test_pattern_getpattern(num3, "a[az*e", 1, "*", false);
mt_test_pattern_getpattern(num4, "a[az*e", 2, "za[a", false);
mt_test_pattern_getpattern(num5, "sa dechire sa race tavu joya", 0, "ayoj uvat ecar as erihced as", false);
//mt_test_pattern_getpattern(num6, "a[\\^*'?\"]b", 2, "b", false);
//mt_test_pattern_getpattern(num7, "1\\[[\\]]\\*a", 0, "1[", false);
//mt_test_pattern_getpattern(num8, "1\\[[\\]]\\*a", 1, "[]]", false);
//mt_test_pattern_getpattern(num9, "1\\[[\\]]\\*a", 2, "*a", false);
//mt_test_pattern_getpattern(num10, "'''['['['']'''[]'", 0, "[", false);
//mt_test_pattern_getpattern(num11, "'''['['['']'''[]'", 1, "['['']", false);
//mt_test_pattern_getpattern(num12, "'''['['['']'''[]'", 2, "[]", false);

void		suite_pattern_substr_rev(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
//	SUITE_ADD_TEST(suite, test_num6);
//	SUITE_ADD_TEST(suite, test_num7);
//	SUITE_ADD_TEST(suite, test_num8);
//	SUITE_ADD_TEST(suite, test_num9);
//	SUITE_ADD_TEST(suite, test_num10);
//	SUITE_ADD_TEST(suite, test_num11);
//	SUITE_ADD_TEST(suite, test_num12);
}

