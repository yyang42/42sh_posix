#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "abc 123",  "abc 123");
mt_test_tokenizer(num2, "aa bb",    "aa bb");
mt_test_tokenizer(num3, "aa  bb",   "aa bb");
mt_test_tokenizer(num4, " aa  bb", 	"aa bb");
mt_test_tokenizer(num5, "aa  bb ", 	"aa bb");
mt_test_tokenizer(num6, "   aa  bb   ", "aa bb");
mt_test_tokenizer(num7, "   ", 		"aa bb");

void	suite_tokenizer_rule8(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
}
