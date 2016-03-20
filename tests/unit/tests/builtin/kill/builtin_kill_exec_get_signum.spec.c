#include <project.h>

#include "shenv/shenv.h"
#include "builtin/cmds/builtin_kill.h"

# define test_get_signum(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		int			result; \
		result = builtin_kill_exec_get_signum(input); \
		if (debug) \
		{ \
			printf("input    : %s\n", input); \
			printf("result   : %d\n", result); \
			printf("expected : %d\n", expected); \
		} \
		mt_assert(result == expected); \
	}

test_get_signum(num1, "0", 0, false);
test_get_signum(num2, "-1", -1, false);
test_get_signum(num2b, "-2", -1, false);
test_get_signum(num3, "31", 31, false);
test_get_signum(num4, "32", -1, false);
test_get_signum(num5, "42", -1, false);
test_get_signum(num6, "KILL", 9, false);
test_get_signum(num7, "USR1", 30, false);
test_get_signum(num8, "HUP", 1, false);
test_get_signum(SIGKILL, "SIGKILL", 9, false);
test_get_signum(SIGHUP, "SIGHUP", 1, false);
test_get_signum(dashdash, "--", -1, false);
test_get_signum(dash, "-", -1, false);

void            suite_builtin_kill_exec_get_signum(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num2b);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_SIGKILL);
	SUITE_ADD_TEST(suite, test_SIGHUP);
	SUITE_ADD_TEST(suite, test_dashdash);
	SUITE_ADD_TEST(suite, test_dash);
}
