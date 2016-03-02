#include <project.h>

#include "arexp/arexp.h"

# define mt_test_eval(name, input, expected, debug)			\
static void test_## name(t_test *test)						\
{															\
	t_arexp		*arexp = arexp_new(input);					\
	long long	actual = arexp_eval(arexp);					\
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
}

mt_test_eval(num01, "1+1", 2LL, false);
mt_test_eval(num02, "1+1+1+1+1", 5LL, false);
mt_test_eval(num03, "2*2", 4LL, false);
mt_test_eval(num04, "2*2+2*2", 8LL, false);
mt_test_eval(num05, "2*2*2*2", 16LL, false);
mt_test_eval(num06, "2*2<<2*2", 64LL, false);

void suite_arexp_eval_simple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
	SUITE_ADD_TEST(suite, test_num06);
}
