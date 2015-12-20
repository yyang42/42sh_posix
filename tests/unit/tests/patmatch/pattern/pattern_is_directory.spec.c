#include <project.h>
#include "pattern.h"

#define PATTERN_TEST(a, b, c) {						\
	t_pattern	*tmp;								\
	tmp = pattern_new(a);							\
	mt_assert(pattern_is_directory(tmp, b) == c);	\
	pattern_del(tmp);								\
}

static void	test_simple(t_test *test)
{
	PATTERN_TEST("Makefile", 0, 0);
	PATTERN_TEST("Makefile/", 0, 1);
	PATTERN_TEST("/Makefile", 0, 0);
	PATTERN_TEST("/Makefile/", 0, 1);
	PATTERN_TEST("/M/k/f/l/e", 0, 1);
	PATTERN_TEST("/M/k/f/l/e", 1, 1);
	PATTERN_TEST("/M/k/f/l/e", 2, 1);
	PATTERN_TEST("/M/k/f/l/e", 3, 1);
	PATTERN_TEST("/M/k/f/l/e", 4, 0);
	PATTERN_TEST("/M/k/f/l/e", 5, 0);
	PATTERN_TEST("/M/k/f/l/e", -1, 0);
}

void		suite_pattern_is_directory(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
