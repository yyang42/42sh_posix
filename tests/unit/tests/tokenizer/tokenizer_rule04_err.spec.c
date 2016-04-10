#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"
#include "shenv/shenv.h"

# define mt_test_tokenizer_err(test_name, input, expected, debug) \
    static void test_## test_name(t_test *test) \
    { \
        t_lst           *tokens; \
        t_tokenizer     *t; \
        t = tokenizer_new(input); \
        tokens = tokenizer_tokenize(t); \
        if (debug) \
        { \
            token_mgr_print(tokens); \
            twl_printf("err_msg  : %s\n", t->err_msg); \
            twl_printf("expected : %s\n", expected); \
        } \
        mt_assert(t->err_msg && strcmp(t->err_msg, expected) == 0); \
        token_mgr_del(tokens); \
    }

mt_test_tokenizer_err(err01, "'",               "42sh: line: 1: tokenizer: looking for matching `''", false);
mt_test_tokenizer_err(err03, "abc'",            "42sh: line: 1: tokenizer: looking for matching `''", false);
mt_test_tokenizer_err(err04, "'a",              "42sh: line: 1: tokenizer: looking for matching `''", false);
mt_test_tokenizer_err(err06, "echo $(\")",      "42sh: line: 1: tokenizer: looking for matching `)'", false);
mt_test_tokenizer_err(err07, "a $(",            "42sh: line: 1: tokenizer: looking for matching `)'", false);
mt_test_tokenizer_err(err08, "a $((1 2) b&",    "42sh: line: 1: tokenizer: looking for matching `))'", false);
mt_test_tokenizer_err(err09, "a ${1 2 3",       "42sh: line: 1: tokenizer: looking for matching `}'", false);

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
