#include <project.h>

#include "token/tokenizer.h"
#include "token/token_list_mgr.h"

# define mt_test_token_mgr_split(test_name, input, split_strings_str, expected, keep_delimiter, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens_list; \
		t_lst			*split_strings; \
		t_lst			*tokens; \
		char			*joined_str; \
		tokens = tokenizer_tokenize(input); \
		split_strings = twl_str_split_to_lst(split_strings_str, "_"); \
		tokens_list = token_mgr_split_ast(tokens, split_strings, keep_delimiter); \
		joined_str = token_list_mgr_strjoin(tokens_list); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("actual   {%s}\n", joined_str); \
			twl_printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		twl_lst_del(split_strings, free); \
		token_mgr_del_inner(tokens); \
		token_list_mgr_del(tokens_list); \
	}

mt_test_token_mgr_split(num1, "echo 1;echo 2", ";",
									"echo_1_; / echo_2", true, false);
mt_test_token_mgr_split(num2, "echo 1 ; echo 2 ; echo 3", ";_&",
									"echo_1_; / echo_2_; / echo_3", true, false);
mt_test_token_mgr_split(num3, "echo 1&echo 2;echo 3", ";_&",
									"echo_1_& / echo_2_; / echo_3", true, false);
mt_test_token_mgr_split(num4, "cmd1;(cmd3;cmd4);cmd5", ";_&",
									"cmd1_; / (_cmd3_;_cmd4_)_; / cmd5", true, false);
mt_test_token_mgr_split(num5, "cmd1;(cmd3;(echo abc)cmd4);cmd5 & cmd6", ";_&",
									"cmd1_; / (_cmd3_;_(_echo_abc_)_cmd4_)_; / cmd5_& / cmd6", true, false);
mt_test_token_mgr_split(num6, "if abc; then 123; fi; echo hello & date", ";_&",
									"if_abc_;_then_123_;_fi_; / echo_hello_& / date", true, false);
mt_test_token_mgr_split(num7, "(echo abc; echo 123) & echo 777", ";_&",
									"(_echo_abc_;_echo_123_)_& / echo_777", true, false);
mt_test_token_mgr_split(num8, "echo 123 | echo abc", "|",
									"echo_123_| / echo_abc", true, false);
mt_test_token_mgr_split(num9, "; ; ; ;", ";", "; / ; / ; / ; / ", true, false);
mt_test_token_mgr_split(num10, "echo a|", "|", "echo_a_| / ", true, false);
mt_test_token_mgr_split(num11, "a;b;c&d", ";_&", "a / b / c / d", false, false);
mt_test_token_mgr_split(num12, "| | |", "|", " /  /  / ", false, false);

mt_test_token_mgr_split(num101, "(abc", ";", "(_abc", true, false);
mt_test_token_mgr_split(num102, "(abc);(", ";", "(_abc_)_; / (", true, false);
mt_test_token_mgr_split(num103, "(aaa;bbb", ";", "(_aaa_;_bbb", true, false);
mt_test_token_mgr_split(num104, "(abc; ; ;", ";", "(_abc_;_;_;", true, false);

void	suite_token_mgr_split_ast(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);

	SUITE_ADD_TEST(suite, test_num101);
	SUITE_ADD_TEST(suite, test_num102);
	SUITE_ADD_TEST(suite, test_num103);
	SUITE_ADD_TEST(suite, test_num104);
}
