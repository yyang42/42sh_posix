#include <project.h>
#include "pattern_matching/patmatch.h"

#define mt_test_patmatch(test_name, input, no_lst, expected, debug)	\
static void test_## test_name(t_test *test)							\
{																	\
	t_patmatch	*tmp = patmatch_new();								\
	t_lst		*lst = patmatch_match(tmp, input);					\
	char		*actual = twl_lst_get(lst, no_lst);					\
	mt_assert(strcmp(actual, expected) == 0);						\
	if (debug)														\
	{																\
		printf("=== case: %s - %i\n", input, no_lst);				\
		printf("actual    {%s}\n", actual);							\
		printf("expected  {%s}\n", expected);						\
	}																\
	twl_lst_del(lst, &free);										\
	patmatch_del(tmp);												\
}

#define mt_test_patmatch_null(test_name, input, no_lst, debug)		\
static void test_## test_name(t_test *test)							\
{																	\
	t_patmatch	*tmp = patmatch_new();								\
	t_lst		*lst = patmatch_match(tmp, input);					\
	char		*actual = twl_lst_get(lst, no_lst);					\
	mt_assert(actual == NULL);										\
	if (debug)														\
	{																\
		printf("=== case: %s - %i\n", input, no_lst);				\
		printf("actual    {%s}\n", actual);							\
		printf("expected  {(null)}\n");								\
	}																\
	twl_lst_del(lst, &free);										\
	patmatch_del(tmp);												\
}

mt_test_patmatch(num1, "/tmp/sandbox/test[0123]", 0, "/tmp/sandbox/test0", false);
mt_test_patmatch(num2, "/tmp/sandbox/test[0123]", 1, "/tmp/sandbox/test1", false);
mt_test_patmatch(num3, "/tmp/sandbox/test[0123]", 2, "/tmp/sandbox/test2", false);
mt_test_patmatch_null(num4, "/tmp/sandbox/test[0123]", 3, false);
mt_test_patmatch(num5, "/tmp/sandbox/test[0-3]", 0, "/tmp/sandbox/test0", false);
mt_test_patmatch(num6, "/tmp/sandbox/test[0-3]", 1, "/tmp/sandbox/test1", false);
mt_test_patmatch(num7, "/tmp/sandbox/test[0-3]", 2, "/tmp/sandbox/test2", false);
mt_test_patmatch_null(num8, "/tmp/sandbox/test[0-3]", 3, false);
mt_test_patmatch(num9, "/tmp/sandbox/test[[:digit:]]", 0, "/tmp/sandbox/test0", false);
mt_test_patmatch(num10, "/tmp/sandbox/test[[:digit:]]", 1, "/tmp/sandbox/test1", false);
mt_test_patmatch(num11, "/tmp/sandbox/test[[:digit:]]", 2, "/tmp/sandbox/test2", false);
mt_test_patmatch_null(num12, "/tmp/sandbox/test[[:digit:]]", 3, false);
mt_test_patmatch(num13, "/tmp/sandbox/test[^a-zA-Z]", 0, "/tmp/sandbox/test0", false);
mt_test_patmatch(num14, "/tmp/sandbox/test[^a-zA-Z]", 1, "/tmp/sandbox/test1", false);
mt_test_patmatch(num15, "/tmp/sandbox/test[^a-zA-Z]", 2, "/tmp/sandbox/test2", false);
mt_test_patmatch_null(num16, "/tmp/sandbox/test[^a-zA-Z]", 3, false);

void		suite_patmatch_match_simple_bracket(t_suite *suite)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
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
}
