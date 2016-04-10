#include <project.h>

#include "token/tokenizer.h"
#include "token/token_list_mgr.h"

# define mt_test_token_mgr_split_by_one_sep(test_name, input, sep, expected, keep_delimiter, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens_list; \
		t_lst			*tokens; \
		char			*joined_str; \
		tokens = tokenizer_utils_tokenize(input); \
		tokens_list = token_mgr_split_by_one_sep(tokens, sep, keep_delimiter); \
		joined_str = token_list_mgr_strjoin(tokens_list); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("actual   {%s}\n", joined_str); \
			twl_printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		token_mgr_del(tokens); \
		token_list_mgr_del_shallow(tokens_list); \
	}

mt_test_token_mgr_split_by_one_sep(num1, "echo 1;echo 2", ";",
									"echo_1_; / echo_2", true, false);
mt_test_token_mgr_split_by_one_sep(num2, "a|b|", "|",
									"a_| / b_| / ", true, false);
mt_test_token_mgr_split_by_one_sep(num3, "a|b|", "|",
									"a / b / ", false, false);

void	suite_token_mgr_split_by_one_sep(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
}
