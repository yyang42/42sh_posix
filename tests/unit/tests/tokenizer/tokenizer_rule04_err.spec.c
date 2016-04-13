#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"
#include "shenv/shenv.h"

mt_test_tokenizer(err01, "'",               "'", false);
mt_test_tokenizer(err03, "abc'",            "abc'", false);
mt_test_tokenizer(err04, "'a",              "'a", false);
mt_test_tokenizer(err06, "echo $(\")",      "echo_$(\")", false);
mt_test_tokenizer(err07, "a $(",            "a_$(", false);
mt_test_tokenizer(err08, "a $((1 2) b&",    "a_$((1 2) b&", false);
mt_test_tokenizer(err09, "a ${1 2 3",       "a_${1 2 3", false);

void    suite_tokenizer_rule04_err(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_err01);
    SUITE_ADD_TEST(suite, test_err03);
    SUITE_ADD_TEST(suite, test_err04);
    SUITE_ADD_TEST(suite, test_err06);
    SUITE_ADD_TEST(suite, test_err07);
    SUITE_ADD_TEST(suite, test_err08);
    SUITE_ADD_TEST(suite, test_err09);
}
