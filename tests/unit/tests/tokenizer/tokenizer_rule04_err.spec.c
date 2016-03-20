#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

# define mt_test_tokenizer_err(test_name, input, expected, debug) \
    static void test_## test_name(t_test *test) \
    { \
        t_lst           *tokens; \
        char            *joined; \
        tokens = tokenizer_tokenize(input); \
        if (debug) \
        { \
            token_mgr_print(tokens); \
        } \
        joined = token_mgr_strjoin(tokens, "_"); \
        mt_assert(strcmp(joined, expected) == 0); \
        free(joined); \
        token_mgr_del_inner(tokens); \
    }

mt_test_tokenizer_err(err01, "'", "", true);

void    suite_tokenizer_rule04_err(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_err01);
}
