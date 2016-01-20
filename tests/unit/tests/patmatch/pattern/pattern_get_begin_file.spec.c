#include <project.h>
#include "pattern_matching/pattern.h"

#define mt_test_pattern_getbeginfile(test_name, input, expected, debug)	\
static void test_## test_name(t_test *test)								\
{																		\
	t_pattern	*tmp = pattern_new(input);								\
	char		actual = pattern_get_begin_file(tmp);					\
	if (debug)															\
	{																	\
		printf("=== case %s\n", input);									\
		printf("actual   -> %c\n", actual);								\
		printf("expected -> %c\n", expected);							\
	}																	\
	mt_assert(pattern_get_begin_file(tmp) == expected);					\
	pattern_del(tmp);													\
}

mt_test_pattern_getbeginfile(num1, "SALUT", '.', false);
mt_test_pattern_getbeginfile(num2, "**/*.[ch]", '.', false);
mt_test_pattern_getbeginfile(num3, "[/.]*", '.', false);
mt_test_pattern_getbeginfile(num4, "\\.\\/a.out", '.', false);
mt_test_pattern_getbeginfile(num5, "\\/\\/\\/GROSTESTTAVU", '/', false);
mt_test_pattern_getbeginfile(num6, "", '\0', false);
mt_test_pattern_getbeginfile(num7, "/bin/sh", '/', false);
mt_test_pattern_getbeginfile(num8, "*/bin/sh", '.', false);
mt_test_pattern_getbeginfile(num9, "?/bin/sh", '.', false);

void		suite_pattern_get_begin_file(t_suite *suite)
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
