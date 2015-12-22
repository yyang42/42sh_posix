#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "> wc",  "> wc", false);
mt_test_tokenizer(num2, ">\nwc",  "> wc", false);
mt_test_tokenizer(num3, ">  wc",  "> wc", false);
mt_test_tokenizer(num04, "ls  &&  wc||date",  "ls && wc || date", true);


void	suite_tokenizer_rule_mix(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num04);
}
