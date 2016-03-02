#include <project.h>

#include "arexp/arexp.h"

# define mt_test_arexp_error(name, input, expected, debug)	\
static void test_## name(t_test *test)						\
{															\
	t_arexp		*arexp = arexp_new(input);					\
	if (debug)												\
	{														\
		printf("=== case %s\n", input);						\
		printf("actual   {%s}\n", arexp->error_msg);		\
		printf("expected {%s}\n", expected);				\
	}														\
	mt_assert(strcmp(arexp->error_msg, expected) == 0);		\
	arexp_del(arexp);										\
}

mt_test_arexp_error(num01, "1 +", "expected operand got nothing", false);
mt_test_arexp_error(num02, "1 1", "unexpected token: 1", false);
mt_test_arexp_error(num03, "1?1,B,c", "expected `:' for conditional expression, got nothing", false);
mt_test_arexp_error(num04, "1&&+=0", "expected operand got +=", false);
mt_test_arexp_error(num05, "12##13", "invalid number: 12##13", false);
mt_test_arexp_error(num06, "(1+1:)", "expected `)' got :", false);
mt_test_arexp_error(num07, "123456789a", "value too great for base: 123456789a", false);
mt_test_arexp_error(num08, "37#abcDEF", "value too great for base: 37#abcDEF", false);
mt_test_arexp_error(num09, "(1,2,)", "expected operand got )", false);
mt_test_arexp_error(num10, "1,2,3?4,5,6:(7,8,9", "expected `)' got nothing", false);
mt_test_arexp_error(num11, "a=-b=c", "unexpected token: =", false);

void suite_arexp_build_error(t_suite *suite)
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
}
