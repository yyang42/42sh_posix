#include <project.h>
#include "pattern_matching/pattern.h"

#define mt_test_pattern_getdepth(test_name, input, expected, debug)	\
static void test_## test_name(t_test *test)							\
{																	\
	t_pattern	*tmp = pattern_new(input);							\
	int			actual = pattern_get_depth(tmp);					\
	if (debug)														\
	{																\
		printf("=== case %s\n", input);								\
		printf("actual   -> %i\n", actual);							\
		printf("expected -> %i\n", expected);						\
	}																\
	mt_assert(actual == expected);									\
	pattern_del(tmp);												\
}

mt_test_pattern_getdepth(num1, "Salut\\ les\\ petits\\ amis", 1, false);
mt_test_pattern_getdepth(num2, "Salut\\ les\\ petits\\ amis/", 2, false);
mt_test_pattern_getdepth(num3, "Salut\\ les\\ petits/amis/", 3, false);
mt_test_pattern_getdepth(num4, "Salut\\ les/petits/amis/", 4, false);
mt_test_pattern_getdepth(num5, "Salut/les/petits/amis/", 5, false);
mt_test_pattern_getdepth(num6, "/Salut/les/petits/amis/", 5, false);
mt_test_pattern_getdepth(num7, "\\///Salut////les////petits//amis////", 5, false);
mt_test_pattern_getdepth(num8, "/////////////////////////////////////", 1, false);

void		suite_pattern_get_depth(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
}
