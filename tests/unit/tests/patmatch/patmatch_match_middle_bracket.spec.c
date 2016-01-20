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

mt_test_patmatch(num1, "/tmp/sandbox/[aze][AZE][123]", 0, "/tmp/sandbox/aZ1", false);
mt_test_patmatch_null(num2, "/tmp/sandbox/[aze][AZE][123]", 1, false);
mt_test_patmatch(num3, "/tmp/sandbox/[a-z][A-Z][0-9]", 0, "/tmp/sandbox/aZ1", false);
mt_test_patmatch_null(num4, "/tmp/sandbox/[a-z][A-Z][0-9]", 1, false);
mt_test_patmatch(num5, "/tmp/sandbox/[[:lower:]][[:upper:]][[:digit:]]", 0, "/tmp/sandbox/aZ1", false);
mt_test_patmatch_null(num6, "/tmp/sandbox/[[:lower:]][[:upper:]][[:digit:]]", 1, false);
mt_test_patmatch(num7, "/tmp/sandbox/[aze[:lower:]a-z-][[:upper:]][[:digit:]]", 0, "/tmp/sandbox/-Z1", false);
mt_test_patmatch(num8, "/tmp/sandbox/[aze[:lower:]a-z-][[:upper:]][[:digit:]]", 1, "/tmp/sandbox/aZ1", false);
mt_test_patmatch_null(num9, "/tmp/sandbx/[aze[:lower:]a-z-][[:upper:]][[:digit:]]", 2, false);
mt_test_patmatch(num10, "/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:]]", 0, "/tmp/sandbox/Z1a", false);
mt_test_patmatch(num11, "/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:]]", 1, "/tmp/sandbox/a1Z", false);
mt_test_patmatch_null(num12, "/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:]]", 2, false);
mt_test_patmatch(num13, "/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:][:alpha:]]", 0, "/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:][:alpha:]]", false);

void		suite_patmatch_match_middle_bracket(t_suite *suite)
{
	reset_sandbox();
	sandbox_cmd("touch -- 1aZ a1Z 1Za Z1a aZ1 Za1 -Z1");
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
}
