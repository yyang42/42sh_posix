#include <project.h>

#include "utils.h"

static void test_that_should_pass(t_test *test)
{
	t_lst			*segs;

	segs = str_split_except_quote("aaa \"1 2\" bbb", " ");
	twl_lst_putstr(segs, "\n");
	printf("\n");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "\"1 2\"") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 2), "bbb") == 0);
}

void	suite_str_split_except_quote(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_that_should_pass);
}
