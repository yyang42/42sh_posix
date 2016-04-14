#include <project.h>

#include "expan/expan_tokenizer.h"

mt_test_expan(num01, "$a", 0, "$a", EXPAN_PARAMETER, false)
mt_test_expan(num02, "${a}", 0, "${a}", EXPAN_PARAMETER, false)
mt_test_expan(num03, "$(ls)", 0, "$(ls)", EXPAN_CMDSBT_DOLLAR, false)
mt_test_expan(num04, "$((1))", 0, "$((1))", EXPAN_ARITHMETIC, false)
mt_test_expan(num05, "${a:-$(ls)}", 0, "${a:-$(ls)}", EXPAN_PARAMETER, false)
mt_test_expan(num06, "$((1+'1'))", 0, "$((1+'1'))", EXPAN_ARITHMETIC, false)
mt_test_expan(num07, "$( (ls) | \"cat\")", 0, "$( (ls) | \"cat\")", EXPAN_CMDSBT_DOLLAR, false)
mt_test_expan(num08, "$(echo '(((')lol", 0, "$(echo '(((')", EXPAN_CMDSBT_DOLLAR, false)
mt_test_expan(num09, "$(($(echo '(((')1`echo ')))'`))", 0, "$(($(echo '(((')1`echo ')))'`))", EXPAN_ARITHMETIC, false)
mt_test_expan(num10, "$123aze", 0, "$1", EXPAN_PARAMETER, false)
mt_test_expan(num11, "$123aze", 1, "23aze", EXPAN_NONE, false)
mt_test_expan(num12, "${##}", 0, "${##}", EXPAN_PARAMETER, false)
mt_test_expan(num13, "$aze123", 0, "$aze123", EXPAN_PARAMETER, false)
mt_test_expan(num14, "$@aze123", 0, "$@", EXPAN_PARAMETER, false)
mt_test_expan(num15, "$@aze123", 1, "aze123", EXPAN_NONE, false)
mt_test_expan(num16, "$(echo ')))')", 0, "$(echo ')))')", EXPAN_CMDSBT_DOLLAR, false)
mt_test_expan(num17, "$}lol", 0, "$", EXPAN_PARAMETER, false)
mt_test_expan(num18, "$}lol", 1, "}lol", EXPAN_NONE, false)
mt_test_expan(num19, "$a_bc", 0, "$a_bc", EXPAN_PARAMETER, false)

void suite_expan_tokenizer_rule06(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num16);
	SUITE_ADD_TEST(suite, test_num17);
	SUITE_ADD_TEST(suite, test_num18);
	SUITE_ADD_TEST(suite, test_num19);
}
