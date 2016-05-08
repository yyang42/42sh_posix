#include <project.h>
#include "pattern_matching/brace/brace.h"

#define mt_brace_expand(test_name, input, no_lst, expected, debug)	\
static void test_## test_name(t_test *test)							\
{																	\
	t_lst	*list = brace_expand(input);							\
	char	*actual = twl_lst_get(list, no_lst);					\
	if (debug)														\
	{																\
		printf("=== case: %s : %i\n", input, no_lst);				\
		printf("actual    {%s}\n", actual);							\
		printf("expected  {%s}\n", expected);						\
	}																\
	mt_assert(strcmp(actual, expected) == 0);						\
	twl_lst_del(list, free);										\
}

mt_brace_expand(num0, "Bonjour", 0, "Bonjour", false);
mt_brace_expand(num1, "{1,2,3}", 0, "1", false);
mt_brace_expand(num2, "{1,2,3}", 1, "2", false);
mt_brace_expand(num3, "{1,2,3}", 2, "3", false);
mt_brace_expand(num4, "aa{11,l{a,o,e}l,33}cc", 0, "aa11cc", false);
mt_brace_expand(num5, "aa{11,l{a,o,e}l,33}cc", 1, "aalalcc", false);
mt_brace_expand(num6, "aa{11,l{a,o,e}l,33}cc", 2, "aalolcc", false);
mt_brace_expand(num7, "aa{11,l{a,o,e}l,33}cc", 3, "aalelcc", false);
mt_brace_expand(num8, "aa{11,l{a,o,e}l,33}cc", 4, "aa33cc", false);

mt_brace_expand(num10, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 0, "aabbddeegghhjj", false);
mt_brace_expand(num11, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 1, "aabbddeeggiijj", false);
mt_brace_expand(num12, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 2, "aabbddffgghhjj", false);
mt_brace_expand(num13, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 3, "aabbddffggiijj", false);
mt_brace_expand(num14, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 4, "aaccddeegghhjj", false);
mt_brace_expand(num15, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 5, "aaccddeeggiijj", false);
mt_brace_expand(num16, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 6, "aaccddffgghhjj", false);
mt_brace_expand(num17, "aa{bb,cc}dd{ee,ff}gg{hh,ii}jj", 7, "aaccddffggiijj", false);

mt_brace_expand(num20, "lel{{01..02},,{a..z..25}}lel", 0, "lel01lel", false);
mt_brace_expand(num21, "lel{{01..02},,{a..z..25}}lel", 1, "lel02lel", false);
mt_brace_expand(num22, "lel{{01..02},,{a..z..25}}lel", 2, "lellel", false);
mt_brace_expand(num23, "lel{{01..02},,{a..z..25}}lel", 3, "lelalel", false);
mt_brace_expand(num24, "lel{{01..02},,{a..z..25}}lel", 4, "lelzlel", false);

void		suite_brace_expand(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num0);
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
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_num14);
	SUITE_ADD_TEST(suite, test_num15);
	SUITE_ADD_TEST(suite, test_num16);
	SUITE_ADD_TEST(suite, test_num17);
	SUITE_ADD_TEST(suite, test_num20);
	SUITE_ADD_TEST(suite, test_num21);
	SUITE_ADD_TEST(suite, test_num22);
	SUITE_ADD_TEST(suite, test_num23);
	SUITE_ADD_TEST(suite, test_num24);
}
