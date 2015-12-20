#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

static void test_rule1(t_test *test)
{
	t_tokenizer		*tokenizer;

	tokenizer = tokenizer_new("");
	mt_assert(twl_lst_len(tokenizer->tokens) == 0);
}

static void tokenizer_tokenize_test(t_test *test)
{
	t_tokenizer		*tokenizer;
	t_token			*token;

	tokenizer = tokenizer_new("aaa bbb ccc");
	// token_mgr_print(tokenizer->tokens);
	mt_assert(twl_lst_len(tokenizer->tokens) == 3);
	token = twl_lst_get(tokenizer->tokens, 0);
	mt_assert(strcmp(token->text, "aaa") == 0);
	token = twl_lst_get(tokenizer->tokens, 1);
	mt_assert(strcmp(token->text, "bbb") == 0);
	token = twl_lst_get(tokenizer->tokens, 2);
	mt_assert(strcmp(token->text, "ccc") == 0);
}

void	suite_tokenizer_tokenize(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_rule1);
	SUITE_ADD_TEST(suite, tokenizer_tokenize_test);
}
