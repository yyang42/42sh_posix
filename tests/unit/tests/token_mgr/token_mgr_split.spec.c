#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

mt_test_token_mgr_split(num1, "echo 1;echo 2", ";",
									"echo_1_; / echo_2", false);
mt_test_token_mgr_split(num2, "echo 1 ; echo 2 ; echo 3", ";_&",
									"echo_1_; / echo_2_; / echo_3", false);
mt_test_token_mgr_split(num3, "echo 1&echo 2;echo 3", ";_&",
									"echo_1_& / echo_2_; / echo_3", false);

// mt_test_token_mgr_split(num4, "cmd1;(cmd3;cmd4);cmd5", ";_&",
// 									"cmd1_; / (_cmd3_;_cmd4_)_; / cmd5", true);

void	suite_token_mgr_split(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	// SUITE_ADD_TEST(suite, test_num4);
}
