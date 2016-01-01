#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "abc 123",  "abc_123", false);
mt_test_tokenizer(num2, "aa bb",    "aa_bb", false);
mt_test_tokenizer(num3, "aa  bb",   "aa_bb", false);
mt_test_tokenizer(num4, " aa  bb", 	"aa_bb", false);
mt_test_tokenizer(num5, "aa  bb ", 	"aa_bb", false);
mt_test_tokenizer(num6, "   aa  bb   ", "aa_bb", false);
mt_test_tokenizer(num7, "   ", 		"", false);
mt_test_tokenizer(num8, "a\\ b c", 	"a\\ b_c", false);

mt_test_tokenizer(num101, "abc\t123",  "abc_123", false);
mt_test_tokenizer(num102, "\taa\t\tbb", 	"aa_bb", false);

void	suite_tokenizer_rule08(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);

	SUITE_ADD_TEST(suite, test_num101);
	SUITE_ADD_TEST(suite, test_num102);
}
