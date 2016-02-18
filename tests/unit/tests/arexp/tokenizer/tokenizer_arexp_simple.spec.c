#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer_arexp(num01, "1+1",                 "1_+_1",           false);
mt_test_tokenizer_arexp(num02, "11+11",               "11_+_11",         false);
mt_test_tokenizer_arexp(num03, "A+=11",               "A_+=_11",         false);
mt_test_tokenizer_arexp(num04, "+-+-1",               "+_-_+_-_1",       false);
mt_test_tokenizer_arexp(num05, "0x1234AB",            "0x1234AB",        false);
mt_test_tokenizer_arexp(num06, "32#LO0OL",            "32#LO0OL",        false);
mt_test_tokenizer_arexp(num07, " 1 + ( 1 ) ",         "1_+_(_1_)",       false);
mt_test_tokenizer_arexp(num08, " 1 +\n\t ( 1 ) ",     "1_+_(_1_)",       false);
mt_test_tokenizer_arexp(num09, "===",                 "==_=",            false);
mt_test_tokenizer_arexp(num10, "ab <= cd && lol",     "ab_<=_cd_&&_lol", false);

void    suite_tokenizer_arexp_simple(t_suite *suite)
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
