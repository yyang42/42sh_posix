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

mt_test_pattern_getpattern(num1, "Makefil[aze", 0, 0, "Makefil[aze", false);
mt_test_pattern_getpattern(num2, "Makefil[az/e]", 0, 0, "Makefil[az", false);
mt_test_pattern_getpattern(num3, "Makefil[az/e]", 1, 0, "e]", false);
mt_test_pattern_getpattern(num4, "Makefil[aze[:digit:]", 0, 0, "Makefil[aze[:digit:]", false);
mt_test_pattern_getpattern(num5, "Makefil[aze[digit:]", 0, 0, "Makefil", false);
mt_test_pattern_getpattern(num6, "Makefil[aze[digit:]", 0, 1, "[aze[digit:]", false);
mt_test_pattern_getpattern(num7, "Makefil[aze[:digit]", 0, 0, "Makefil[aze[:digit]", false);
mt_test_pattern_getpattern(num8, "Makefil[aze[.t]", 0, 0, "Makefil[aze[.t]", false);
mt_test_pattern_getpattern(num9, "Makefil[aze[=t]", 0, 0, "Makefil[aze[=t]", false);
mt_test_pattern_getpattern(num10, "Makefil[aze[:digit:][.a.][=b=]azw]", 0, 0, "Makefil", false);
mt_test_pattern_getpattern(num11, "Makefil[aze[:digit:][.a.][=b=]azw]", 0, 1, "[aze[:digit:][.a.][=b=]azw]", false);
mt_test_pattern_getpattern(num12, "a[b[.[:[=b=]:].]b]c", 0, 0, "a", false);
mt_test_pattern_getpattern(num13, "a[b[.[:[=b=]:].]b]c", 0, 1, "[b[.[:[=b=]:].]b]", false);
mt_test_pattern_getpattern(num14, "a[b[.[:[=b=]:].]b]c", 0, 2, "c", false);
mt_test_pattern_getpattern(num15, "a[b[.[:[=b.]:]=]b]c", 0, 0, "a", false);
mt_test_pattern_getpattern(num16, "a[b[.[:[=b.]:]=]b]c", 0, 1, "[b[.[:[=b.]:]=]b]", false);
mt_test_pattern_getpattern(num17, "a[b[.[:[=b.]:]=]b]c", 0, 2, "c", false);

void		suite_pattern_get_pattern_brackle(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num15);
	SUITE_ADD_TEST(suite, test_num16);
	SUITE_ADD_TEST(suite, test_num17);
}
