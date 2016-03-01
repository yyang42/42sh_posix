#include <project.h>

#include "arexp/arexp.h"

# define mt_test_atoll(name, input, expected, debug)		\
static void test_## name(t_test *test)						\
{															\
	t_arexp		*arexp = arexp_new(input);					\
	t_token		*token = token_arexp(input);				\
	long long	actual = arexp_atoll(arexp, token);			\
	if (debug)												\
	{														\
		printf("=== case %s\n", input);						\
		printf("actual   {%lli}\n", actual);				\
		printf("expected {%lli}\n", expected);				\
		if (arexp->error_msg)								\
			printf("error    {%s}\n", arexp->error_msg);	\
	}														\
	mt_assert(actual == expected);							\
	arexp_del(arexp);										\
	token_del(token);										\
}

mt_test_atoll(num01, "1",                        1LL,                    false);
mt_test_atoll(num02, "0xa",                      10LL,                   false);
mt_test_atoll(num03, "010",                      8LL,                    false);
mt_test_atoll(num04, "64#_",                     63LL,                   false);
mt_test_atoll(num05, "111111111111111111111111", 6371555158481727943LL,  false);
mt_test_atoll(num06, "9223372036854775807",      9223372036854775807LL,  false);
mt_test_atoll(num07, "0XdEaDBeEf",               3735928559LL,           false);
mt_test_atoll(num08, "2#0011001100110011",       13107LL,                false);
mt_test_atoll(num09, "23#0011001100110011",      525952865838850656LL,   false);
mt_test_atoll(num10, "21#ABcdEFgh",              19005986828LL,          false);
mt_test_atoll(num11, "53#LoL",                   133342LL,               false);
mt_test_atoll(num12, "60#MdR",                   173633LL,               false);

void suite_arexp_atoll_simple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
	SUITE_ADD_TEST(suite, test_num06);
	SUITE_ADD_TEST(suite, test_num07);
	SUITE_ADD_TEST(suite, test_num08);
	SUITE_ADD_TEST(suite, test_num09);
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
}
