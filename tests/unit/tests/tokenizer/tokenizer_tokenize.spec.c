#include <project.h>

#include "tokenizer.h"

static void test_rule1(t_test *test)
{
	t_tokenizer		*tokenizer;

	tokenizer = tokenizer_new("");
	mt_assert(twl_lst_len(tokenizer->tokens) == 0);
}

static void tokenizer_tokenize_test(t_test *test)
{
	t_tokenizer		*tokenizer;

	tokenizer = tokenizer_new("aaa bbb ccc");
	twl_lst_putstr(tokenizer->tokens, "\n");
	printf("\n");
	mt_assert(twl_lst_len(tokenizer->tokens) == 3);
	mt_assert(strcmp(twl_lst_get(tokenizer->tokens, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(tokenizer->tokens, 1), "bbb") == 0);
	mt_assert(strcmp(twl_lst_get(tokenizer->tokens, 2), "ccc") == 0);
}

void	suite_tokenizer_tokenize(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_rule1);
	SUITE_ADD_TEST(suite, tokenizer_tokenize_test);
}
