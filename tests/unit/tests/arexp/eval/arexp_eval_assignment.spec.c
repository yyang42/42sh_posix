#include <project.h>

#include "arexp/arexp.h"
#include "shenv/shenv.h"
#include <limits.h>

# define mt_test_eval(name, input, assign, expected, debug)	\
static void test_## name(t_test *test)						\
{															\
	t_arexp		*arexp = arexp_new(input);					\
	arexp_eval(arexp);										\
	char *actual = shenv_shvars_get_value(				\
			shenv_singleton(), assign);				\
	if (debug)												\
	{														\
		printf("=== case %s %s\n", input, assign);			\
		printf("actual   {%s}\n", actual);					\
		printf("expected {%s}\n", expected);				\
		if (arexp->error_msg)								\
			printf("error    {%s}\n", arexp->error_msg);	\
	}														\
	mt_assert(strcmp(actual, expected) == 0);				\
	arexp_del(arexp);										\
}

mt_test_eval(num00, "a=0,b=0,c=0,d=0", "d", "0", false);
mt_test_eval(num01, "a=42", "a", "42", false);
mt_test_eval(num02, "b+=b+=b+=b+=b+=10", "b", "160", false);
mt_test_eval(num03, "c=35#666", "c", "7566", false);
mt_test_eval(num04, "a=10,b=20,c=a+b", "c", "30", false);
mt_test_eval(num05, "a=14,a|=1", "a", "15", false);
mt_test_eval(num06, "a=10, a*=10", "a", "100", false);
mt_test_eval(num07, "a=1, b=2, (c=3,d=4)", "a", "1", false);
mt_test_eval(num08, "a=1, b=2, (c=3,d=4)", "b", "2", false);
mt_test_eval(num09, "a=1, b=2, (c=3,d=4)", "c", "3", false);
mt_test_eval(num10, "a=1, b=2, (c=3,d=4)", "d", "4", false);
mt_test_eval(num11, "a=10, a-=3", "a", "7", false);
mt_test_eval(num12, "a=12, a/=-3", "a", "-4", false);
mt_test_eval(num13, "a=666, a %= 10", "a", "6", false);
mt_test_eval(num14, "a=b=12", "a", "12", false);
mt_test_eval(num15, "a=1, a<<=5", "a", "32", false);
mt_test_eval(num16, "a", "a", "32", false);

void suite_arexp_eval_assignment(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num00);
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
	SUITE_ADD_TEST(suite, test_num16);
}
