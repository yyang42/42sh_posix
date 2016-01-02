#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer(num01, "> wc",                 ">_wc",                 false);
mt_test_tokenizer(num02, ">\nwc",                ">_\n_wc",              false);
mt_test_tokenizer(num03, ">  wc",                ">_wc",                 false);
mt_test_tokenizer(num04, "ls  &&  wc||date",     "ls_&&_wc_||_date",     false);

void    suite_tokenizer_rule_mix(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_num01);
    SUITE_ADD_TEST(suite, test_num02);
    SUITE_ADD_TEST(suite, test_num03);
    SUITE_ADD_TEST(suite, test_num04);
}
