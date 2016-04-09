#include <project.h>

#include "expan/expan_tokenizer.h"

mt_test_expan(num01, "echo", 0, "echo", EXPAN_NONE, false)

static void test_num02(t_test *test)
{
	t_lst			*tokens = expan_tokenizer_tokenize("");
	mt_assert(twl_lst_len(tokens) == 0);
	twl_lst_del(tokens, expan_token_del);
}

void suite_expan_tokenizer_rule01(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
}
