#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer(num1, "abc\n123",     "abc_\n_123", false);
mt_test_tokenizer(num2, "aa\nbb",       "aa_\n_bb", false);
mt_test_tokenizer(num3, "aa\n\nbb",     "aa_\n_\n_bb", false);
mt_test_tokenizer(num4, "\naa\n\nbb", 	"\n_aa_\n_\n_bb", false);
mt_test_tokenizer(num5, "aa\n\nbb\n", 	"aa_\n_\n_bb_\n", false);
mt_test_tokenizer(num6, "\n\n\naa\n\nbb", "\n_\n_\n_aa_\n_\n_bb", false);
mt_test_tokenizer(num7, "a\\\nb", 		"ab", false);

void	suite_tokenizer_rule07(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
}
