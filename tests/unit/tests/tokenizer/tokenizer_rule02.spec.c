#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer(num1, "aa&&bb",               "aa_&&_bb", false);
mt_test_tokenizer(num2, "aa&&&bb",              "aa_&&_&_bb", false);
mt_test_tokenizer(num3, "aa&&bb||cc<<-dd",      "aa_&&_bb_||_cc_<<-_dd", false);
mt_test_tokenizer(num4, "aa>bb",                "aa_>_bb", false);
mt_test_tokenizer(num5, "aa\\>bb",              "aa\\>bb", false);
mt_test_tokenizer(num6, "aa\\&&bb",             "aa\\&_&_bb", false);
mt_test_tokenizer(num7, "aa;;bb",               "aa_;;_bb", false);
mt_test_tokenizer(num8, "aa;bb",                "aa_;_bb", false);
mt_test_tokenizer(num9, "aa<<bb",               "aa_<<_bb", false);
mt_test_tokenizer(num10, "aa<&bb",              "aa_<&_bb", false);
mt_test_tokenizer(num11, "aa>&bb",              "aa_>&_bb", false);
mt_test_tokenizer(num12, "aa<>bb",              "aa_<>_bb", false);
mt_test_tokenizer(num13, "aa>|bb",              "aa_>|_bb", false);
mt_test_tokenizer(num14, "aa>>bb",              "aa_>>_bb", false);
mt_test_tokenizer(num15, "; ;",                 ";_;", false);

void    suite_tokenizer_rule02(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_num1);
    SUITE_ADD_TEST(suite, test_num2);
    SUITE_ADD_TEST(suite, test_num3);
    SUITE_ADD_TEST(suite, test_num4);
    SUITE_ADD_TEST(suite, test_num5);
    SUITE_ADD_TEST(suite, test_num6);
    SUITE_ADD_TEST(suite, test_num7);
    SUITE_ADD_TEST(suite, test_num8);
    SUITE_ADD_TEST(suite, test_num9);
    SUITE_ADD_TEST(suite, test_num10);
    SUITE_ADD_TEST(suite, test_num11);
    SUITE_ADD_TEST(suite, test_num12);
    SUITE_ADD_TEST(suite, test_num13);
    SUITE_ADD_TEST(suite, test_num14);
    SUITE_ADD_TEST(suite, test_num15);
}
