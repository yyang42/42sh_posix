#include <project.h>
#include "pattern_matching/brace/brace_tokenizer.h"

#define mt_brace_tokenizer(test_name, input, no_lst, exptype, exptext, explist, debug)		\
static void test_## test_name(t_test *test)							\
{																	\
	t_brace_token		expected = { exptype, exptext, explist };	\
	t_lst				*list = brace_tokenizer_tokenize(input);	\
	t_brace_token		*actual = twl_lst_get(list, no_lst);		\
	if (debug)														\
	{																\
		printf("=== case: %s : %i\n", input, no_lst);				\
		printf("TYPE\nactual    {%i}\n", actual->type);				\
		printf("expected  {%i}\n", expected.type);					\
		printf("TEXT\nactual    {%s}\n", actual->text);				\
		printf("expected  {%s}\n", expected.text);					\
		printf("LIST\nactual    {%p}\n", actual->brace_list);		\
		printf("expected  {%p}\n", expected.brace_list);			\
	}																\
	mt_assert(actual->type == expected.type);						\
	mt_assert(strcmp(actual->text, expected.text) == 0);			\
	mt_assert(actual->brace_list == expected.brace_list);			\
	twl_lst_del(list, brace_token_del);								\
}

mt_brace_tokenizer(num1, "lol", 0, BRACE_IGNORE, "lol", NULL, false);

mt_brace_tokenizer(num2, "lel{1..3..5}pouet", 0, BRACE_IGNORE, "lel", NULL, false);
mt_brace_tokenizer(num3, "lel{1..3..5}pouet", 1, BRACE_SEQUENCE_DIGIT, "1..3..5", NULL, false);
mt_brace_tokenizer(num4, "lel{1..3..5}pouet", 2, BRACE_IGNORE, "pouet", NULL, false);

mt_brace_tokenizer(num5, "lel{a..z..+5}pouet", 0, BRACE_IGNORE, "lel", NULL, false);
mt_brace_tokenizer(num6, "lel{a..z..+5}pouet", 1, BRACE_SEQUENCE_ALPHA, "a..z..+5", NULL, false);
mt_brace_tokenizer(num7, "lel{a..z..+5}pouet", 2, BRACE_IGNORE, "pouet", NULL, false);

mt_brace_tokenizer(num8, "$({echo,abc})`{ls,-la}`${hihi}", 0, BRACE_IGNORE, "$({echo,abc})`{ls,-la}`${hihi}", NULL, false);
mt_brace_tokenizer(num9, "'{brace1}'\"brace2\"\\{hihi\\}", 0, BRACE_IGNORE, "'{brace1}'\"brace2\"\\{hihi\\}", NULL, false);
mt_brace_tokenizer(num10, "a{\\{\\,lel\\,\\\\\\}}b", 0, BRACE_IGNORE, "a{\\{\\,lel\\,\\\\\\}}b", NULL, false);

void		suite_brace_tokenizer(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_num9);
	SUITE_ADD_TEST(suite, test_num10);
}
