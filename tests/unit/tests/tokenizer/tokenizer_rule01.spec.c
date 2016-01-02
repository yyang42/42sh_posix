#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer(num1, "",        "",      false);
mt_test_tokenizer(num2, "aaa",     "aaa",   false);

void    suite_tokenizer_rule01(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_num1);
    SUITE_ADD_TEST(suite, test_num2);
}
