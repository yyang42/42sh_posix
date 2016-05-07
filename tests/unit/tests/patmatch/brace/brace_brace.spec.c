#include <project.h>
#include "pattern_matching/brace/brace_tokenizer.h"

#define mt_brace_brace(test_name, input, no_lst, expected, debug)	\
static void test_## test_name(t_test *test)							\
{																	\
	t_lst	*list = brace_tokenizer_tokenize(input);				\
	t_brace_token	*token = twl_lst_get(list, 0);					\
	mt_assert(token->type != BRACE_IGNORE);							\
	char	*actual = twl_lst_get(token->brace_list, no_lst);		\
	if (debug)														\
	{																\
		printf("=== case: %s : %i\n", input, no_lst);				\
		printf("actual    {%s}\n", actual);							\
		printf("expected  {%s}\n", expected);						\
	}																\
	mt_assert(strcmp(actual, expected) == 0);						\
	twl_lst_del(list, brace_token_del);								\
}

mt_brace_brace(num1, "{1,2,3}", 0, "1", false);
mt_brace_brace(num2, "{1,2,3}", 1, "2", false);
mt_brace_brace(num3, "{1,2,3}", 2, "3", false);

mt_brace_brace(num4, "{aa`echo '}'`bb,cc{1..10}dd,}", 0, "aa`echo '}'`bb", false);
mt_brace_brace(num5, "{aa`echo '}'`bb,cc{1..10}dd,}", 1, "cc{1..10}dd", false);
mt_brace_brace(num6, "{aa`echo '}'`bb,cc{1..10}dd,}", 2, "", false);

mt_brace_brace(num7, "{,,,}", 3, "", false);

mt_brace_brace(num8, "{1..6..2}", 2, "5", false);
mt_brace_brace(num9, "{a..z..5}", 2, "k", false);

void		suite_brace_brace(t_suite *suite)
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
}
