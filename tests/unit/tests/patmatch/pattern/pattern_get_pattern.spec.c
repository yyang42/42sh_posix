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

static void	test_bracle(t_test *test)
{
	PATTERN_TEST("Makefil[aze", 0, 0, "Makefil[aze");
	PATTERN_TEST("Makefil[az/e]", 0, 0, "Makefil[az");
	PATTERN_TEST("Makefil[az/e]", 1, 0, "e]");
	PATTERN_TEST("Makefil[aze[:digit:]", 0, 0, "Makefil[aze[:digit:]");
	PATTERN_TEST("Makefil[aze[digit:]", 0, 0, "Makefil");
	PATTERN_TEST("Makefil[aze[digit:]", 0, 1, "[aze[digit:]");
	PATTERN_TEST("Makefil[aze[:digit]", 0, 0, "Makefil[aze[:digit]");
	PATTERN_TEST("Makefil[aze[.t]", 0, 0, "Makefil[aze[.t]");
	PATTERN_TEST("Makefil[aze[=t]", 0, 0, "Makefil[aze[=t]");
	PATTERN_TEST("Makefil[aze[:digit:][.a.][=b=]azw]", 0, 0, "Makefil");
	PATTERN_TEST("Makefil[aze[:digit:][.a.][=b=]azw]", 0, 1, "[aze[:digit:][.a.][=b=]azw]");
	PATTERN_TEST("a[b[.[:[=b=]:].]b]c", 0, 0, "a");
	PATTERN_TEST("a[b[.[:[=b=]:].]b]c", 0, 1, "[b[.[:[=b=]:].]b]");
	PATTERN_TEST("a[b[.[:[=b=]:].]b]c", 0, 2, "c");
	PATTERN_TEST("a[b[.[:[=b.]:]=]b]c", 0, 0, "a");
	PATTERN_TEST("a[b[.[:[=b.]:]=]b]c", 0, 1, "[b[.[:[=b.]:]=]b]");
	PATTERN_TEST("a[b[.[:[=b.]:]=]b]c", 0, 2, "c");
}

void		suite_pattern_get_pattern(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_middle);
	SUITE_ADD_TEST(suite, test_hardle);
	SUITE_ADD_TEST(suite, test_bracle);
}
