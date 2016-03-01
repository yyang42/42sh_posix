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

void suite_arexp_build_error(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
}
