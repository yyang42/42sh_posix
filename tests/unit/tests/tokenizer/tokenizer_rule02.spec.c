#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "aa&&bb", 	            "aa_&&_bb", false);
mt_test_tokenizer(num2, "aa&&&bb",     	        "aa_&&_&_bb", false);
mt_test_tokenizer(num3, "aa&&bb||cc<<-dd",     	"aa_&&_bb_||_cc_<<-_dd", false);

void	suite_tokenizer_rule02(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
}
