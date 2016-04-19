#include <project.h>
#include "pattern_matching/pattern.h"

#define mt_test_pattern_get_num(test_name, input, index, expected, debug)	\
static void test_## test_name(t_test *test)									\
{																			\
	t_pattern	*tmp = pattern_new(input);									\
	int			actual = pattern_get_num_slash(tmp, index);					\
	if (debug)																\
	{																		\
		printf("=== case %s\n", input);										\
		printf("actual   -> %i\n", actual);									\
		printf("expected -> %i\n", expected);								\
	}																		\
	mt_assert(actual == expected);											\
	pattern_del(tmp);														\
}

mt_test_pattern_get_num(num1, "ls", 0, 0, false);
mt_test_pattern_get_num(num2, "/bin/ls", 0, 1, false);
mt_test_pattern_get_num(num3, "/bin/ls", 1, 1, false);
mt_test_pattern_get_num(num4, "./a.out", 0, 1, false);
mt_test_pattern_get_num(num5, "///BIN/LS///LOL", 0, 3, false);
mt_test_pattern_get_num(num6, "///BIN/LS///LOL", 1, 1, false);
mt_test_pattern_get_num(num7, "///BIN/LS///LOL", 2, 3, false);
mt_test_pattern_get_num(num8, "///BIN/LS///LOL", 3, 0, false);
mt_test_pattern_get_num(num9, ".//////file/////executable", 0, 6, false);
mt_test_pattern_get_num(num10, ".//////file/////executable", 1, 5, false);
mt_test_pattern_get_num(num11, ".//////file/////executable", 2, 0, false);
mt_test_pattern_get_num(num12, "'/'\\/\"/\"/pouf", 0, 4, false);
mt_test_pattern_get_num(num13, "'/'\\/\"/\"/pouf", 1, 0, false);
mt_test_pattern_get_num(num14, "*/*/*", 0, 1, false);
mt_test_pattern_get_num(num15, "*/*/*", 1, 1, false);
mt_test_pattern_get_num(num16, "*//*'*'*//*", 0, 2, false);
mt_test_pattern_get_num(num17, "*//*'*'*//*", 1, 2, false);
mt_test_pattern_get_num(num18, "*//*'*'*/a/*", 1, 1, false);
mt_test_pattern_get_num(num19, "*//*'*'*/a/*", 2, 1, false);

void        suite_pattern_get_num_slash(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num17);
	SUITE_ADD_TEST(suite, test_num18);
	SUITE_ADD_TEST(suite, test_num19);
}
