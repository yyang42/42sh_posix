#include <project.h>
#include "pattern_matching/brace/brace.h"

#define mt_brace_seq_digit(test_name, input, no_lst, expected, debug)\
static void test_## test_name(t_test *test)							\
{																	\
	t_lst	*list = brace_expand_sequence_digit(input);				\
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

mt_brace_seq_digit(num0, "0..2", 0, "0", false);
mt_brace_seq_digit(num1, "0..2", 1, "1", false);
mt_brace_seq_digit(num2, "0..2", 2, "2", false);

mt_brace_seq_digit(num3, "0..2..2", 0, "0", false);
mt_brace_seq_digit(num4, "0..2..2", 1, "2", false);

mt_brace_seq_digit(num5, "0..0", 0, "0", false);

mt_brace_seq_digit(num6, "000..120..+09", 0, "000", false);
mt_brace_seq_digit(num7, "000..120..+09", 1, "009", false);
mt_brace_seq_digit(num8, "000..120..+09", 5, "045", false);
mt_brace_seq_digit(num9, "000..120..+09", 12, "108", false);

mt_brace_seq_digit(num10, "+12..-0033..+7", 0, "00012", false);
mt_brace_seq_digit(num11, "+12..-0033..+7", 2, "-0002", false);
mt_brace_seq_digit(num12, "+12..-0033..+7", 6, "-0030", false);

void		suite_brace_seq_digit(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num9);
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
}
