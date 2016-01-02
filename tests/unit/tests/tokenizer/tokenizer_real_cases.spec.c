#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"

mt_test_tokenizer(num1, "echo abc | wc",  "echo_abc_|_wc", false);
mt_test_tokenizer(num2, "if [ 1 -eq 2 ]; then echo ok; else echo ko; fi",
						"if_[_1_-eq_2_]_;_then_echo_ok_;_else_echo_ko_;_fi", false);
mt_test_tokenizer(num3, "for file in `ls`; do echo $file;done;",
						"for_file_in_`ls`_;_do_echo_$file_;_done_;", false);
mt_test_tokenizer(num4, "functionName () {\necho abc\n}",
						"functionName_(_)_{_\n_echo_abc_\n_}", false);

void	suite_tokenizer_real_cases(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
}
