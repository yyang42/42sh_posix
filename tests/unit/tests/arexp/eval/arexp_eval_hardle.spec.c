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
mt_test_eval(num03, "(a=-42,b=42,c=14),c*=a==b||b>a?c=33,(1<<1)|1:44", 42LL, false);
mt_test_eval(num04, "(a=1,b=2,c=3,d=4),(e=5,f=g=h=-7),i=13,j=k=33", 33LL, false);
mt_test_eval(num05, "a+=b-=c*=d/=e%=f|=g&=h^=i<<=j>>=k=42", 3LL, false);
mt_test_eval(num06, "(a+=1)<=12", 1LL, false);
mt_test_eval(num07, "(a+=12)<=12", 0LL, false);
mt_test_eval(num08, "(b=33,c=76),a=b<c?a=b>c?~b: ! ~b,~b:~c", -34LL, false);

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
}
