#include <project.h>

#include "arexp/arexp.h"
#include <limits.h>
#include "shenv/shenv.h"

# define mt_test_eval(name, input, expected, debug)			\
static void test_## name(t_test *test)						\
{															\
	t_arexp		*arexp = arexp_new(input);					\
	arexp_eval(arexp);										\
	char		*actual = arexp->error_msg;					\
	if (debug)												\
	{														\
		printf("=== case %s\n", input);						\
		printf("actual   {%s}\n", actual);					\
		printf("expected {%s}\n", expected);				\
	}														\
	mt_assert(strcmp(actual, expected) == 0);				\
	arexp_del(arexp);										\
}

mt_test_eval(num01, "1/0", "division by 0", false);
mt_test_eval(num02, "1%0", "division by 0", false);
mt_test_eval(num03, "a", "value too great for base: Bonjour", false);
mt_test_eval(num04, "a=100, a/(a>>10)", "division by 0", false);
mt_test_eval(num05, "a=100, a%(a>>10)", "division by 0", false);

void suite_arexp_eval_error(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	shenv_setenv_value(shenv_singleton(), "a", "Bonjour", NULL);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
}
