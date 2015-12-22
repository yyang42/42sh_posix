#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_tokenizer(num1, "a bb", 	            "a_bb", true);

void	suite_tokenizer_rule04(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
}
