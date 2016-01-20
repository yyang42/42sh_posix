#include <project.h>
#include "pattern_matching/pattern.h"

#define PATTERN_TEST(a, b) {						\
	t_pattern	*tmp;								\
	tmp = pattern_new(a);							\
	mt_assert(pattern_get_depth(tmp) == b);			\
	pattern_del(tmp);								\
}

static void	test_simple(t_test *test)
{
	PATTERN_TEST("Salut\\ les\\ petits\\ amis", 1);
	PATTERN_TEST("Salut\\ les\\ petits\\ amis/", 2);
	PATTERN_TEST("Salut\\ les\\ petits/amis/", 3);
	PATTERN_TEST("Salut\\ les/petits/amis/", 4);
	PATTERN_TEST("Salut/les/petits/amis/", 5);
	PATTERN_TEST("/Salut/les/petits/amis/", 5);
	PATTERN_TEST("\\///Salut////les////petits//amis////", 5);
	PATTERN_TEST("/////////////////////////////////////", 1);
}

void		suite_pattern_get_depth(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
