#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

# define mt_test_tokenizer_line_no(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens; \
		char			*actual; \
		tokens = tokenizer_utils_tokenize(input); \
		actual = token_mgr_strjoin_with_num(tokens); \
		if (debug) \
		{ \
			printf("==== case : %s", input); \
			printf("actual    {%s}\n", actual); \
			printf("expected  {%s}\n", expected); \
		} \
		mt_assert(strcmp(actual, expected) == 0); \
		token_mgr_del(tokens); \
		free(actual); \
	}

mt_test_tokenizer_line_no(num1, "echo abc 123\n", "echo(1:1)_abc(1:6)_123(1:10)_\n(1:13)", false);
mt_test_tokenizer_line_no(num2, "echo abc\necho bbb\n", "echo(1:1)_abc(1:6)_\n(1:9)_echo(2:1)_bbb(2:6)_\n(2:9)", false);
mt_test_tokenizer_line_no(num3, "echo 'a\nb' 123\n", "echo(1:1)_'a\nb'(1:6)_123(2:4)_\n(2:7)", false);
mt_test_tokenizer_line_no(num4, "echo 'a\n\nb' 123\n", "echo(1:1)_'a\n\nb'(1:6)_123(3:4)_\n(3:7)", false);
mt_test_tokenizer_line_no(num5, "\n", "\n(1:1)", false);
mt_test_tokenizer_line_no(num6, "", "", false);
mt_test_tokenizer_line_no(num7, "\n\n\n", "\n(1:1)_\n(2:1)_\n(3:1)", false);

void	suite_tokenizer_line_number(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
}
