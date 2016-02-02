#include <project.h>
#include "pattern_matching/pattern.h"

#define mt_test_pattern_isdirectory(test_name, input, nb, expected, debug)	\
static void test_## test_name(t_test *test)									\
{																			\
	t_pattern	*tmp = pattern_new(input);									\
	int			actual = pattern_is_directory(tmp, nb);						\
	if (debug)																\
	{																		\
		printf("=== case %s - %i\n", input, nb);							\
		printf("actual   -> %i\n", actual);									\
		printf("expected -> %i\n", expected);								\
	}																		\
	mt_assert(actual == expected);											\
	pattern_del(tmp);														\
}

mt_test_pattern_isdirectory(num1, "Makefile", 0, 0, false);
mt_test_pattern_isdirectory(num2, "Makefile/", 0, 1, false);
mt_test_pattern_isdirectory(num3, "/Makefile", 0, 0, false);
mt_test_pattern_isdirectory(num4, "/Makefile/", 0, 1, false);
mt_test_pattern_isdirectory(num5, "/M/k/f/l/e", 0, 1, false);
mt_test_pattern_isdirectory(num6, "/M/k/f/l/e", 1, 1, false);
mt_test_pattern_isdirectory(num7, "/M/k/f/l/e", 2, 1, false);
mt_test_pattern_isdirectory(num8, "/M/k/f/l/e", 3, 1, false);
mt_test_pattern_isdirectory(num9, "/M/k/f/l/e", 4, 0, false);
mt_test_pattern_isdirectory(num10, "/M/k/f/l/e", 5, 0, false);
mt_test_pattern_isdirectory(num11, "/M/k/f/l/e", -1, 0, false);

void		suite_pattern_is_directory(t_suite *suite)
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
}
