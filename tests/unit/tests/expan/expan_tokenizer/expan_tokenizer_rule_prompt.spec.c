#include <project.h>
#include "expan/expan_tokenizer.h"

# define mt_test_expan_prompt(name, input, no, expectedtext, expectedtype, debug)	\
static void test_## name(t_test *test)										\
{																			\
	t_lst			*tokens = expan_tokenizer_tokenize_prompt(input);		\
	t_expan_token	*token = twl_lst_get(tokens, no);						\
	if (debug && token)														\
	{																		\
		printf("  input:    %s\n", input);									\
		printf("  actual:   %s\n", token->text);							\
		printf("  expected: %s\n", expectedtext);							\
	}																		\
	mt_assert(token != NULL);												\
	mt_assert(strcmp(token->text, expectedtext) == 0);						\
	mt_assert(token->type == expectedtype);									\
	twl_lst_del(tokens, expan_token_del);									\
}

mt_test_expan_prompt(num01, "\\l\\s", 0, "\\l\\s", EXPAN_NONE, false)
mt_test_expan_prompt(num02, "$(pwd)\\upouet", 0, "$(pwd)", EXPAN_CMDSBT_DOLLAR, false)
mt_test_expan_prompt(num03, "$(pwd)\\upouet", 1, "\\u", EXPAN_PROMPT, false)
mt_test_expan_prompt(num04, "$(pwd)\\upouet", 2, "pouet", EXPAN_NONE, false)
mt_test_expan_prompt(num05, "aa\\xfFbb\\000cc", 1, "\\xfF", EXPAN_PROMPT_NUMBER, false)
mt_test_expan_prompt(num06, "aa\\xfFbb\\000cc", 3, "\\000", EXPAN_PROMPT_NUMBER, false)

void suite_expan_tokenizer_rule_prompt(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
	SUITE_ADD_TEST(suite, test_num06);
}
