#include <project.h>

#include "expan/expan_tokenizer.h"

mt_test_expan(num01, "``", 0, "``", EXPAN_CMDSBT_BQUOTE, false)
mt_test_expan(num02, "````", 0, "``", EXPAN_CMDSBT_BQUOTE, false)
mt_test_expan(num03, "````", 1, "``", EXPAN_CMDSBT_BQUOTE, false)
mt_test_expan(num04, "`\\`\\``", 0, "`\\`\\``", EXPAN_CMDSBT_BQUOTE, false)
mt_test_expan(num06, "pouet`echo 'echo abc'`", 0, "pouet", EXPAN_NONE, false)
mt_test_expan(num07, "pouet`echo 'echo abc'`", 1, "`echo 'echo abc'`", EXPAN_CMDSBT_BQUOTE, false)
mt_test_expan(num08, "`$(echo `lol`)`", 0, "`$(echo `", EXPAN_CMDSBT_BQUOTE, false)
mt_test_expan(num09, "`$(echo `lol`)`", 1, "lol", EXPAN_NONE, false)
mt_test_expan(num10, "`$(echo `lol`)`", 2, "`)`", EXPAN_CMDSBT_BQUOTE, false)

void suite_expan_tokenizer_rule04(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num06);
	SUITE_ADD_TEST(suite, test_num07);
	SUITE_ADD_TEST(suite, test_num08);
	SUITE_ADD_TEST(suite, test_num09);
	SUITE_ADD_TEST(suite, test_num10);
}
