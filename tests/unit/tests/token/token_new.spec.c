#include <project.h>

#include "token.h"
#include "token_type.h"

# define mt_test_token_new(test_name, input, expected_type) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert((token_new(input)->type) == expected_type); \
	}

mt_test_token_new(num1, "\n", TOKEN_NEWLINE);
mt_test_token_new(num2, "&&", TOKEN_AND_IF);
mt_test_token_new(num3, "||", TOKEN_OR_IF);
mt_test_token_new(num4, ";;", TOKEN_DSEMI);
mt_test_token_new(num5, "<<", TOKEN_DLESS);
mt_test_token_new(num6, ">>", TOKEN_DGREAT);
mt_test_token_new(num7, "<&", TOKEN_LESSAND);
mt_test_token_new(num8, ">&", TOKEN_GREATAND);
mt_test_token_new(num9, "<>", TOKEN_LESSGREAT);
mt_test_token_new(num10, "<<-", TOKEN_DLESSDASH);
mt_test_token_new(num11, ">|", TOKEN_CLOBBER);
mt_test_token_new(num12, "if", TOKEN_IF);
mt_test_token_new(num13, "then", TOKEN_THEN);
mt_test_token_new(num14, "else", TOKEN_ELSE);
mt_test_token_new(num15, "elif", TOKEN_ELIF);
mt_test_token_new(num16, "fi", TOKEN_FI);
mt_test_token_new(num17, "do", TOKEN_DO);
mt_test_token_new(num18, "done", TOKEN_DONE);
mt_test_token_new(num19, "case", TOKEN_CASE);
mt_test_token_new(num20, "esac", TOKEN_ESAC);
mt_test_token_new(num21, "while", TOKEN_WHILE);
mt_test_token_new(num22, "until", TOKEN_UNTIL);
mt_test_token_new(num23, "for", TOKEN_FOR);
mt_test_token_new(num24, "{", TOKEN_LBRACE);
mt_test_token_new(num25, "}", TOKEN_RBRACE);
mt_test_token_new(num26, "!", TOKEN_BANG);
mt_test_token_new(num27, "in", TOKEN_IN);
mt_test_token_new(num28, "xyz", TOKEN_TOKEN);

void	suite_token_new(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num16);
	SUITE_ADD_TEST(suite, test_num17);
	SUITE_ADD_TEST(suite, test_num18);
	SUITE_ADD_TEST(suite, test_num19);
	SUITE_ADD_TEST(suite, test_num20);
	SUITE_ADD_TEST(suite, test_num21);
	SUITE_ADD_TEST(suite, test_num22);
	SUITE_ADD_TEST(suite, test_num23);
	SUITE_ADD_TEST(suite, test_num24);
	SUITE_ADD_TEST(suite, test_num25);
	SUITE_ADD_TEST(suite, test_num26);
	SUITE_ADD_TEST(suite, test_num27);
	SUITE_ADD_TEST(suite, test_num28);
}
