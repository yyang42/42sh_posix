#include <project.h>
#include "pattern_matching/brace/brace.h"

#define mt_brace_seq_alpha(test_name, input, no_lst, expected, debug)\
static void test_## test_name(t_test *test)							\
{																	\
	t_lst	*list = brace_expand_sequence_alpha(input);				\
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

mt_brace_seq_alpha(num0, "a..c", 0, "a", false);
mt_brace_seq_alpha(num1, "a..c", 1, "b", false);
mt_brace_seq_alpha(num2, "a..c", 2, "c", false);

mt_brace_seq_alpha(num3, "a..c..+2", 0, "a", false);
mt_brace_seq_alpha(num4, "a..c..+2", 1, "c", false);

mt_brace_seq_alpha(num5, "a..c..190", 0, "a", false);

mt_brace_seq_alpha(num6, "A..z..3", 10, "_", false);
mt_brace_seq_alpha(num7, "A..z..3", 19, "z", false);
mt_brace_seq_alpha(num8, "A..z..-3", 10, "_", false);
mt_brace_seq_alpha(num9, "A..z..-3", 19, "z", false);
mt_brace_seq_alpha(num10, "z..A..-5", 6, "\\", true);
mt_brace_seq_alpha(num11, "z..A..-5", 9, "M", true);


void		suite_brace_seq_alpha(t_suite *suite)
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
}
