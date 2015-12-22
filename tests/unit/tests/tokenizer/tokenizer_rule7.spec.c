#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "abc\n123",     "abc 123", false);
mt_test_tokenizer(num2, "aa\nbb",       "aa bb", false);
mt_test_tokenizer(num3, "aa\n\nbb",     "aa bb", false);
mt_test_tokenizer(num4, "\naa\n\nbb", 	"aa bb", false);
mt_test_tokenizer(num5, "aa\n\nbb\n", 	"aa bb", false);
mt_test_tokenizer(num6, "\n\n\naa\n\nbb\n\n\n", "aa bb", false);
mt_test_tokenizer(num7, "\n\n\n", 		"", false);

void	suite_tokenizer_rule7(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
}
