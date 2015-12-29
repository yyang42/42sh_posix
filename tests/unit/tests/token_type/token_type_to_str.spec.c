#include <project.h>

#include "token_type.h"

# define mt_test_token_type_from_str(test_name, input, type) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(strcmp(token_type_to_str(type), input) == 0); \
	}

# define mt_test_token_type_from_str_equal(test_name, input, type) \
	static void test_## test_name(t_test *test) \
	{ \
		mt_assert(token_type_to_str(type) == input); \
	}


mt_test_token_type_from_str(num1, "\n", TOKEN_NEWLINE);
mt_test_token_type_from_str(num2, "&&", TOKEN_AND_IF);
mt_test_token_type_from_str(num3, "||", TOKEN_OR_IF);
mt_test_token_type_from_str(num4, ";;", TOKEN_DSEMI);
mt_test_token_type_from_str(num5, "<<", TOKEN_DLESS);
mt_test_token_type_from_str(num6, ">>", TOKEN_DGREAT);
mt_test_token_type_from_str(num7, "<&", TOKEN_LESSAND);
mt_test_token_type_from_str(num8, ">&", TOKEN_GREATAND);
mt_test_token_type_from_str(num9, "<>", TOKEN_LESSGREAT);
mt_test_token_type_from_str(num10, "<<-", TOKEN_DLESSDASH);
mt_test_token_type_from_str(num11, ">|", TOKEN_CLOBBER);
mt_test_token_type_from_str(num12, "if", TOKEN_IF);
mt_test_token_type_from_str(num13, "then", TOKEN_THEN);
mt_test_token_type_from_str(num14, "else", TOKEN_ELSE);
mt_test_token_type_from_str(num15, "elif", TOKEN_ELIF);
mt_test_token_type_from_str(num16, "fi", TOKEN_FI);
mt_test_token_type_from_str(num17, "do", TOKEN_DO);
mt_test_token_type_from_str(num18, "done", TOKEN_DONE);
mt_test_token_type_from_str(num19, "case", TOKEN_CASE);
mt_test_token_type_from_str(num20, "esac", TOKEN_ESAC);
mt_test_token_type_from_str(num21, "while", TOKEN_WHILE);
mt_test_token_type_from_str(num22, "until", TOKEN_UNTIL);
mt_test_token_type_from_str(num23, "for", TOKEN_FOR);
mt_test_token_type_from_str(num24, "{", TOKEN_LBRACE);
mt_test_token_type_from_str(num25, "}", TOKEN_RBRACE);
mt_test_token_type_from_str(num26, "!", TOKEN_BANG);
mt_test_token_type_from_str(num27, "in", TOKEN_IN);
mt_test_token_type_from_str_equal(num28, NULL, TOKEN_TOKEN);

void	suite_token_type_to_str(t_suite *suite)
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
