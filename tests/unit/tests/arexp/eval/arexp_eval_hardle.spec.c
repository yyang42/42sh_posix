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

mt_test_eval(num01, "", 0LL, false);
mt_test_eval(num02, "(a=12,b=13,c=14),a*b<<c", 2555904LL, false);
mt_test_eval(num03, "(a=-42,b=42),c*=a==b||b>a?c=33,(1<<1)|1:44", 99LL, false);
mt_test_eval(num04, "0", 0LL, false);
mt_test_eval(num05, "0", 0LL, false);
mt_test_eval(num06, "0", 0LL, false);
mt_test_eval(num07, "0", 0LL, false);
mt_test_eval(num08, "0", 0LL, false);
mt_test_eval(num09, "0", 0LL, false);
mt_test_eval(num10, "0", 0LL, false);
mt_test_eval(num11, "0", 0LL, false);
mt_test_eval(num12, "0", 0LL, false);
mt_test_eval(num13, "0", 0LL, false);
mt_test_eval(num14, "0", 0LL, false);
mt_test_eval(num15, "0", 0LL, false);

void suite_arexp_eval_hardle(t_suite *suite)
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
