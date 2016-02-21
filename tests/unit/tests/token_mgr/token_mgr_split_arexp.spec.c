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
		tokens = tokenizer_arexp_tokenize(input); \
		split_strings = twl_str_split_to_lst(split_strings_str, "_"); \
		tokens_list = token_mgr_split_arexp(tokens, split_strings, keep_delimiter); \
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

mt_test_token_mgr_split(num1, "1, 2, 3", ",", "1_, / 2_, / 3", true, false);
mt_test_token_mgr_split(num2, "1, (2, 3)", ",", "1_, / (_2_,_3_)", true, false);
mt_test_token_mgr_split(num3, "a=2*(2,(3,4)),(2, 3)", ",",
		"a_=_2_*_(_2_,_(_3_,_4_)_)_, / (_2_,_3_)", true, false);

void	suite_token_mgr_split_arexp(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
}
