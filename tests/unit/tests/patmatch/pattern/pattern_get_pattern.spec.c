#include <project.h>
#include "pattern.h"

#define PATTERN_TEST(str, nulst, nudata, cmp) {					\
	t_pattern		*tmp = pattern_new(str);					\
	t_lst			*lst = pattern_get_pattern(tmp, nulst);		\
	t_pattern_data	*data = twl_lst_get(lst, nudata);			\
	mt_assert(strcmp(data->split, cmp) == 0);					\
	pattern_del(tmp);											\
}


static void	test_simple(t_test *test)
{
	PATTERN_TEST("/usr/bin/ls", 0, 0, "usr");
	PATTERN_TEST("/usr/bin/ls", 1, 0, "bin");
	PATTERN_TEST("/usr/bin/ls", 2, 0, "ls");
	PATTERN_TEST("tests/unit/", 0, 0, "tests");
	PATTERN_TEST("tests/unit/", 1, 0, "unit");
}

static void	test_middle(t_test *test)
{
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 0, 0, "u");
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 0, 1, "*");
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 0, 2, "r");
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 1, 0, "b");
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 1, 1, "[[:lower:]]");
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 1, 2, "n");
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 2, 0, "l");
	PATTERN_TEST("/u*r/b[[:lower:]]n/l?", 2, 1, "?");
}

static void	test_hardle(t_test *test)
{
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 0, 0, "u");
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 0, 1, "*");
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 0, 2, "r");
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 1, 0, "b");
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 1, 1, "[[:lower:]]");
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 1, 2, "n");
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 2, 0, "l");
	PATTERN_TEST("/////u*r/////b[[:lower:]]n/////l?", 2, 1, "?");
}

void		suite_pattern_get_pattern(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_middle);
	SUITE_ADD_TEST(suite, test_hardle);
}
