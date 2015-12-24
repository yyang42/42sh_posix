#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "a $(1 2) b",               "a_$(1 2)_b",    false);
mt_test_tokenizer(num2, "a b$(1 2)c d",             "a_b$(1 2)c_d",  false);
mt_test_tokenizer(num3, "a `1 2` b",                "a_`1 2`_b",     false);
mt_test_tokenizer(num4, "a b`1 2`c d",              "a_b`1 2`c_d",   false);
mt_test_tokenizer(num5, "a $ABC",                   "a_$ABC",        false);
mt_test_tokenizer(num6, "a $",                      "a_$",           false);
mt_test_tokenizer(num7, "a $(",                     "a_$(",          false);
mt_test_tokenizer(num8, "a ${1 2} b",               "a_${1 2}_b",    false);
mt_test_tokenizer(num9, "a $((1 2)) b",             "a_$((1 2))_b",  false);
mt_test_tokenizer(num10,"a $((1 2) b&",             "a_$((1 2) b&",  false);
mt_test_tokenizer(num11,"a ${1 2 3",                "a_${1 2 3",     false);
mt_test_tokenizer(num12,"a $(1 \n 2) b",            "a_$(1 \n 2)_b", false);

void    suite_tokenizer_rule05(t_suite *suite)
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
}
