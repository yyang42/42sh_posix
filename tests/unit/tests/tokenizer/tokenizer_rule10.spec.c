#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer(num1, "abc#123\nxyz",  "abc_\n_xyz", false);
mt_test_tokenizer(num2, "abc\\#123\nxyz",  "abc\\#123_\n_xyz", false);
mt_test_tokenizer(num3, "#",  "", false);
mt_test_tokenizer(num4, "#abc",  "", false);
mt_test_tokenizer(num5, "\\#",  "\\#", false);

void	suite_tokenizer_rule10(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
}
