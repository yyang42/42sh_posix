#include <project.h>

#include "token_type.h"

# define mt_test_token_type_get_type(test_name, input, type) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(token_type_get_type(input) == type); \
	}

mt_test_token_type_get_type(num1, "\n", TOKEN_NEWLINE);
mt_test_token_type_get_type(num2, "&&", TOKEN_AND_IF);
mt_test_token_type_get_type(num3, "&&", TOKEN_AND_IF);
mt_test_token_type_get_type(num4, "||", TOKEN_OR_IF);
mt_test_token_type_get_type(num5, ";;", TOKEN_DSEMI);
mt_test_token_type_get_type(num6, "<<", TOKEN_DLESS);
mt_test_token_type_get_type(num7, ">>", TOKEN_DGREAT);
mt_test_token_type_get_type(num8, "<&", TOKEN_LESSAND);
mt_test_token_type_get_type(num9, ">&", TOKEN_GREATAND);
mt_test_token_type_get_type(num10, "<>", TOKEN_LESSGREAT);
mt_test_token_type_get_type(num11, "<<-", TOKEN_DLESSDASH);
mt_test_token_type_get_type(num12, ">|", TOKEN_CLOBBER);
mt_test_token_type_get_type(num13, "if", TOKEN_IF);
mt_test_token_type_get_type(num14, "then", TOKEN_THEN);
mt_test_token_type_get_type(num15, "else", TOKEN_ELSE);
mt_test_token_type_get_type(num16, "elif", TOKEN_ELIF);
mt_test_token_type_get_type(num17, "fi", TOKEN_FI);
mt_test_token_type_get_type(num18, "do", TOKEN_DO);
mt_test_token_type_get_type(num19, "done", TOKEN_DONE);
mt_test_token_type_get_type(num20, "case", TOKEN_CASE);
mt_test_token_type_get_type(num21, "esac", TOKEN_ESAC);
mt_test_token_type_get_type(num22, "while", TOKEN_WHILE);
mt_test_token_type_get_type(num23, "until", TOKEN_UNTIL);
mt_test_token_type_get_type(num24, "for", TOKEN_FOR);
mt_test_token_type_get_type(num25, "{", TOKEN_LBRACE);
mt_test_token_type_get_type(num26, "}", TOKEN_RBRACE);
mt_test_token_type_get_type(num27, "!", TOKEN_BANG);
mt_test_token_type_get_type(num28, "in", TOKEN_IN);
mt_test_token_type_get_type(num29, "xyz", TOKEN_UNKNOWN);

void	suite_token_type_get_type(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num29);
}
