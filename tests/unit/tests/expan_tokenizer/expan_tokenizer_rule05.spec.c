#include <project.h>

#include "expan/expan_tokenizer.h"

mt_test_expan(num01, "\"\"", 0, "\"\"", EXPAN_DQUOTE, false)
mt_test_expan(num02, "\"\"\"\"", 0, "\"\"", EXPAN_DQUOTE, false)
mt_test_expan(num03, "\"\"\"\"", 1, "\"\"", EXPAN_DQUOTE, false)
mt_test_expan(num04, "\"\\\"\\\\\"", 0, "\"\\\"\\\\\"", EXPAN_DQUOTE, false)
mt_test_expan(num05, "\"$(echo \"lol\")\"", 0, "\"$(echo \"lol\")\"", EXPAN_DQUOTE, false)
mt_test_expan(num06, "abc\"def\"ghi", 0, "abc", EXPAN_NONE, false)
mt_test_expan(num07, "abc\"def\"ghi", 1, "\"def\"", EXPAN_DQUOTE, false)
mt_test_expan(num08, "abc\"def\"ghi", 2, "ghi", EXPAN_NONE, false)
mt_test_expan(num09, "\"`echo \"lol\"`\"", 0, "\"`echo \"lol\"`\"", EXPAN_DQUOTE, false)
mt_test_expan(num10, "\"${a:-$(echo \"lol\")}\"", 0, "\"${a:-$(echo \"lol\")}\"", EXPAN_DQUOTE, false)

void suite_expan_tokenizer_rule05(t_suite *suite)
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
}
