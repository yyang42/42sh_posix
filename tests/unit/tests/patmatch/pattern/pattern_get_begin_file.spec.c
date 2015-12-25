#include <project.h>
#include "pattern.h"

#define PATTERN_TEST(a, b) {						\
	t_pattern	*tmp;								\
	tmp = pattern_new(a);							\
	mt_assert(pattern_get_begin_file(tmp) == b);	\
	pattern_del(tmp);								\
}

static void	test_simple(t_test *test)
{
	PATTERN_TEST("SALUT", '.');
	PATTERN_TEST("**/*.[ch]", '.');
	PATTERN_TEST("[/.]*", '.');
	PATTERN_TEST("\\.\\/a.out", '.');
	PATTERN_TEST("\\/\\/\\/GROSTESTTAVU", '/');
	PATTERN_TEST("", '\0');
	PATTERN_TEST("/bin/sh", '/');
	PATTERN_TEST("*/bin/sh", '.');
	PATTERN_TEST("?/bin/sh", '.');
}

void		suite_pattern_get_begin_file(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
