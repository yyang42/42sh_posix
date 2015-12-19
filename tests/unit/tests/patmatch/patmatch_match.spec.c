#include <project.h>
#include "patmatch.h"

#define PATTERN_TEST(a, b) {						\
	t_pattern	*tmp;								\
	tmp = pattern_new(a);							\
	mt_assert(pattern_get_begin_file(tmp) == b);	\
	pattern_del(tmp);								\
}

static void	test_simple(t_test *test)
{
	t_patmatch *m = patmatch_new();

	patmatch_match(m, "/.*");
	(void)test;
}

void		suite_patmatch_match(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
