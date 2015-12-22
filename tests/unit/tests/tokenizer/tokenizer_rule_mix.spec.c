#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "> wc",  ">_wc", false);
mt_test_tokenizer(num2, ">\nwc",  ">_wc", false);
mt_test_tokenizer(num3, ">  wc",  ">_wc", false);
mt_test_tokenizer(num04, "ls  &&  wc||date",  "ls_&&_wc_||_date", false);


void	suite_tokenizer_rule_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num04);
}
