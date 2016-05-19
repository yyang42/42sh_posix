#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

# define mt_test_tokenizer_line_no(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		char			*actual; \
		actual = strdup(input); \
		tokenizer_utils_remove_line_continuation(actual); \
		if (debug) \
		{ \
			printf("==== case : %s\n", input); \
			printf("actual    {%s}\n", actual); \
			printf("expected  {%s}\n\n", expected); \
		} \
		mt_assert(strcmp(actual, expected) == 0); \
		free(actual); \
	}

mt_test_tokenizer_line_no(num1, "aa\\\nbb",           "aabb", false);
mt_test_tokenizer_line_no(num2, "aa\\\n\\\nbb",       "aabb", false);
mt_test_tokenizer_line_no(num3, "\\\n",               "", false);
mt_test_tokenizer_line_no(num4, "\\\na",              "a", false);
mt_test_tokenizer_line_no(num5, "'\\\na'",            "'\\\na'", false);
mt_test_tokenizer_line_no(num6, "'\\\n'",             "'\\\n'", false);
mt_test_tokenizer_line_no(num7, "\\'a'1\\\n2'b\\'c",  "\\'a'1\\\n2'b\\'c", false);
mt_test_tokenizer_line_no(num8, "\\'a'1\\\n2'",       "\\'a'1\\\n2'", false);
mt_test_tokenizer_line_no(num9, "\\",                 "\\", false);
mt_test_tokenizer_line_no(num10, "a'\\\\\\\nbb'",     "a'\\\\\\\nbb'", false);
mt_test_tokenizer_line_no(num11, "\"'a\\\nb'\"",      "\"'ab'\"", false);

void	suite_tokenizer_utils_remove_line_continuation(t_suite *suite)
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
}
