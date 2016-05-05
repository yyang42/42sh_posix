#include <project.h>
#include "pattern_matching/brace/brace_tokenizer.h"

#define mt_test_brace_tokenizer(test_name, input, expected, debug)	\
static void test_## test_name(t_test *test)							\
{																	\
	t_brace_tokenizer	*tmp = brace_tokenizer_new(input);			\
	t_brace_token_type	actual = brace_could_push_brace(tmp);		\
	if (debug)														\
	{																\
		printf("=== case: %s\n", input);							\
		printf("actual    {%i}\n", actual);							\
		printf("expected  {%i}\n", expected);						\
	}																\
	mt_assert(actual == expected);									\
	brace_tokenizer_del(tmp);										\
}

mt_test_brace_tokenizer(num1, "{0..1}", BRACE_SEQUENCE_DIGIT, false);
mt_test_brace_tokenizer(num2, "{0..1..2}", BRACE_SEQUENCE_DIGIT, false);
mt_test_brace_tokenizer(num3, "{-3223..+1123..-666}lel", BRACE_SEQUENCE_DIGIT, false);

mt_test_brace_tokenizer(num4, "{a..z}", BRACE_SEQUENCE_ALPHA, false);
mt_test_brace_tokenizer(num5, "{a..z..3}", BRACE_SEQUENCE_ALPHA, false);
mt_test_brace_tokenizer(num6, "{K..p..+55}lel", BRACE_SEQUENCE_ALPHA, false);

mt_test_brace_tokenizer(num7, "{a}", BRACE_IGNORE, false);
mt_test_brace_tokenizer(num8, "{a,}", BRACE_LIST, false);
mt_test_brace_tokenizer(num9, "{a,{1..2}}", BRACE_LIST, false);
mt_test_brace_tokenizer(num10, "{{1..9}}", BRACE_IGNORE, false);
mt_test_brace_tokenizer(num11, "{a,b,{1..9}", BRACE_IGNORE, false);
mt_test_brace_tokenizer(num12, "{a,{b,{1..9},c}}", BRACE_LIST, false);
mt_test_brace_tokenizer(num13, "{a,{b,{1..9},c}lel", BRACE_IGNORE, false);
mt_test_brace_tokenizer(num14, "{a..z..,hihi}", BRACE_LIST, false);
mt_test_brace_tokenizer(num15, "{$(echo '}'),'}',\"}\"}", BRACE_LIST, false);

void		suite_brace_could_match(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_num14);
	SUITE_ADD_TEST(suite, test_num15);
}
