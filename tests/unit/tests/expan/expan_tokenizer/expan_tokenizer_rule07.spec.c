#include <project.h>

#include "expan/expan_tokenizer.h"

mt_test_expan(num01, "\\\"", 0, "\\\"", EXPAN_NONE, false)
mt_test_expan(num02, "\\'", 0, "\\'", EXPAN_NONE, false)
mt_test_expan(num03, "\\$", 0, "\\$", EXPAN_NONE, false)
mt_test_expan(num04, "\\`", 0, "\\`", EXPAN_NONE, false)
mt_test_expan(num05, "\\ ", 0, "\\ ", EXPAN_NONE, false)
mt_test_expan(num06, "Mes\\ Applications", 0, "Mes\\ Applications", EXPAN_NONE, false)
mt_test_expan(num07, "Mes\\'Jeux\\'", 0, "Mes\\'Jeux\\'", EXPAN_NONE, false)
mt_test_expan(num08, "Mer\\`iletfou\\`", 0, "Mer\\`iletfou\\`", EXPAN_NONE, false)
mt_test_expan(num09, "lol", 0, "lol", EXPAN_NONE, false)

void suite_expan_tokenizer_rule07(t_suite *suite)
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
}
