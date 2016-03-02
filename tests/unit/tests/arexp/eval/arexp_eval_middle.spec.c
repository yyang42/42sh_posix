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

mt_test_eval(num01, "1+1-1-1?1,2,3:3?2:1", 2LL, false);
mt_test_eval(num02, "1<=3^3&&12>42", 0LL, false);
mt_test_eval(num03, "(12>3&&-7<0)?7<<32#10:55#33", 30064771072LL, false);
mt_test_eval(num04, "2+2*2<<2*2+3>>1", 384LL, false);
mt_test_eval(num05, "10>>-1", 0LL, false);
mt_test_eval(num06, "(2+2*2<<2*2+3>>-1)+1", 1LL, false);
mt_test_eval(num07, "(~((55*33)-(45>>4)))*-+077", 114282LL, false);
mt_test_eval(num08, "0x10+0X10+010+10+2#10", 52LL, false);
mt_test_eval(num09, "-(-(-(1<<1)-2)*3)", -12LL, false);
mt_test_eval(num10, "12<33>0<=1", 1LL, false);
mt_test_eval(num11, "12!=12==0?~~12:-12", 12LL, false);
mt_test_eval(num12, "63#@*64#_", 3906LL, false);
mt_test_eval(num13, "(144&335|667)^2#10010011101110", 9845LL, false);
mt_test_eval(num14, "-00+0<<0*0^0|0&0*0-0", 0LL, false);
mt_test_eval(num15, "(4456333<(-32, 33, 00033333333) && (1, 22, 333))? 44==45? 12? 12?13: 14!=33 ? 12 : 33: 666*2<<5:(10+1)*(1<<2)-2#10 : 64#lol", 42LL, false);

void suite_arexp_eval_middle(t_suite *suite)
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
