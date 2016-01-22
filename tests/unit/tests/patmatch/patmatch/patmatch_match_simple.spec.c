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

mt_test_patmatch(num1, "/tmp/sandbox/test0", 0, "/tmp/sandbox/test0", false);
mt_test_patmatch(num2, "/tmp/sandbox/test1", 0, "/tmp/sandbox/test1", false);
mt_test_patmatch(num3, "/tmp/sandbox/test2", 0, "/tmp/sandbox/test2", false);
mt_test_patmatch(num4, "/tmp/sandbox/.", 0, "/tmp/sandbox/.", false);
mt_test_patmatch(num5, "/tmp/sandbox", 0, "/tmp/sandbox", false);
mt_test_patmatch(num6, "/tmp/sandbox/", 0, "/tmp/sandbox/", false);
mt_test_patmatch(num7, "/tmp/sandbox/test3", 0, "/tmp/sandbox/test3", false);

void		suite_patmatch_match_simple(t_suite *suite)
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
}
