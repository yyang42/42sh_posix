#include <project.h>

#include "expan/expan_tokenizer.h"

mt_test_expan(num01, "''", 0, "''", EXPAN_SQUOTE, false)
mt_test_expan(num02, "''''", 0, "''", EXPAN_SQUOTE, false)
mt_test_expan(num03, "''''", 1, "''", EXPAN_SQUOTE, false)
mt_test_expan(num04, "'\\'''", 0, "'\\'", EXPAN_SQUOTE, false)
mt_test_expan(num05, "'\\'''", 1, "''", EXPAN_SQUOTE, false)

void suite_expan_tokenizer_rule03(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
}
