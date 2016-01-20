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

mt_test_patmatch(num1, "/tmp/sandbox/*[[:digit:]]/???*[^[:digit:]]", 0, "/tmp/sandbox/test6/pouf", false);
mt_test_patmatch_null(num2, "/tmp/sandbox/*[[:digit:]]/???*[^[:digit:]]", 1, false);
mt_test_patmatch(num3, "/tmp/sandbox/*?[[:lower:]]?[[:digit:]]*/*?[[:lower:]]?[[:digit:]]*/**?**?**?**?**", 0, "/tmp/sandbox/test0/test5/pouf", false);
mt_test_patmatch(num4, "/tmp/sandbox/*?[[:lower:]]?[[:digit:]]*/*?[[:lower:]]?[[:digit:]]*/**?**?**?**?**/", 0, "/tmp/sandbox/*?[[:lower:]]?[[:digit:]]*/*?[[:lower:]]?[[:digit:]]*/**?**?**?**?**/", false);

void		suite_patmatch_match_melting_pot(t_suite *suite)
{
	reset_sandbox();
	sandbox_cmd("mkdir -p test0/test0 test0/test5 test1/test0 test2/test0 test3/test0 test4/test0 test5/test0 test5/test5 && ln -s test0/test5 test6 && touch test0/test5/pouf");
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
}
