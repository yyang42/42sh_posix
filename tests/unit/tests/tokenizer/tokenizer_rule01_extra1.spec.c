#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num01, "(echo abc)",    "(_echo_abc_)",    false);
mt_test_tokenizer(num02, "()",            "(_)",             false);
mt_test_tokenizer(num03, "()()",          "(_)_(_)",         false);

mt_test_tokenizer(num101, "(echo abc)",    "(_echo_abc_)",    false);
mt_test_tokenizer(num102, "()",            "(_)",             false);
mt_test_tokenizer(num103, "()()",          "(_)_(_)",         false);

void    suite_tokenizer_rule01_extra1(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_num01);
    SUITE_ADD_TEST(suite, test_num02);
    SUITE_ADD_TEST(suite, test_num03);

    SUITE_ADD_TEST(suite, test_num101);
    SUITE_ADD_TEST(suite, test_num102);
    SUITE_ADD_TEST(suite, test_num103);
}
