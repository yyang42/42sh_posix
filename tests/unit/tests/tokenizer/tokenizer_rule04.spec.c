#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer(num1, "a 1\\ 2 b",                "a_1\\ 2_b", false);
mt_test_tokenizer(num2, "a '1 2' b",                "a_'1 2'_b", false);
mt_test_tokenizer(num3, "a '1$(a b c) 2' b",        "a_'1$(a b c) 2'_b", false);
mt_test_tokenizer(num4, "a \"1$(a b c) 2\" b",      "a_\"1$(a b c) 2\"_b", false);
mt_test_tokenizer(num5, "\\ ",                      "\\ ", false);
mt_test_tokenizer(num6, "a '1 \\\"2' b",            "a_'1 \\\"2'_b", false);
mt_test_tokenizer(num7, "a&'1 2'&3",                "a_&_'1 2'_&_3", false);
mt_test_tokenizer(num8, "a b'c d'e f",              "a_b'c d'e_f", false);
mt_test_tokenizer(num9, "1 a` 'b`c`d'`xyz 2", "1_a` 'b`c`d'`xyz_2", false);
mt_test_tokenizer(num13, "1 $( ` $( ' ' ) ` ) 2",   "1_$( ` $( ' ' ) ` )_2", false);
mt_test_tokenizer(num14, "$(`$(`$($(`a b`))`)`)cd ef",   "$(`$(`$($(`a b`))`)`)cd_ef", false);
mt_test_tokenizer(num15, "a $(($($($(())))))1 b",        "a_$(($($($(())))))1_b", false);
mt_test_tokenizer(num16, "\"a'b\" c",               "\"a'b\"_c", false);
mt_test_tokenizer(num17, "echo \"$( echo \" abc \" )\"", "echo_\"$( echo \" abc \" )\"", false);
mt_test_tokenizer(num19, "echo '$('", "echo_'$('", false);
mt_test_tokenizer(num20, "echo $(echo '$(')", "echo_$(echo '$(')", false);

void    suite_tokenizer_rule04(t_suite *suite)
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
    SUITE_ADD_TEST(suite, test_num13);
    SUITE_ADD_TEST(suite, test_num14);
    SUITE_ADD_TEST(suite, test_num15);
    SUITE_ADD_TEST(suite, test_num16);
    SUITE_ADD_TEST(suite, test_num17);
    SUITE_ADD_TEST(suite, test_num19);
    SUITE_ADD_TEST(suite, test_num20);
}
