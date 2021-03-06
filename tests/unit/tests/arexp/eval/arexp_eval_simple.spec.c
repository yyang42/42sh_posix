#include <project.h>

#include "arexp/arexp.h"
#include <limits.h>

# define mt_test_eval(name, input, expected, debug)			\
static void test_## name(t_test *test)						\
{															\
	t_arexp		*arexp = arexp_new(input);					\
	long long	actual = arexp_eval(arexp);					\
	if (debug)												\
	{														\
		printf("=== case %s\n", input);						\
		printf("actual   {%lli}\n", actual);				\
		printf("expected {%lli}\n", (long long)expected);	\
		if (arexp->error_msg)								\
			printf("error    {%s}\n", arexp->error_msg);	\
	}														\
	mt_assert(actual == expected);							\
	arexp_del(arexp);										\
}

mt_test_eval(num01, "1+1", 2LL, false);
mt_test_eval(num02, "1+1+1+1+1", 5LL, false);
mt_test_eval(num03, "2*2", 4LL, false);
mt_test_eval(num04, "2*2+2*2", 8LL, false);
mt_test_eval(num05, "2*2*2*2", 16LL, false);
mt_test_eval(num06, "2^3", 1LL, false);
mt_test_eval(num07, "~35", -36LL, false);
mt_test_eval(num08, "(((12)))", 12LL, false);
mt_test_eval(num09, "-(((12)))", -12LL, false);
mt_test_eval(num10, "33*77%41", 40LL, false);
mt_test_eval(num11, " ! ! 1664", 1LL, false);
mt_test_eval(num12, "~~--++--++--++42", 42LL, false);
mt_test_eval(num13, "1*2*3*(4*5*6*7*8*9*(--10))", 3628800LL, false);
mt_test_eval(num14, "9223372036854775807", LLONG_MAX, false);
mt_test_eval(num15, "--9223372036854775808", LLONG_MIN, false);

void suite_arexp_eval_simple(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_num14);
	SUITE_ADD_TEST(suite, test_num15);
}
