#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"
#include "token/token_list_mgr.h"

# define mt_test_extract_assign(test_name, input, expected, remain, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens_list; \
		t_lst			*tokens; \
		t_lst			*remaining_tokens; \
		char			*joined_str; \
		char			*remaining_str; \
		remaining_tokens = twl_lst_new(); \
		tokens = tokenizer_tokenize(input); \
		tokens_list = token_mgr_extract_assignment(tokens, remaining_tokens); \
		joined_str = token_mgr_strjoin(tokens_list, "_"); \
		remaining_str = token_mgr_strjoin(remaining_tokens, "_"); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("input         {%s}\n", input); \
			twl_printf("actual        {%s}\n", joined_str); \
			twl_printf("expected      {%s}\n", expected); \
			twl_printf("remaining_str {%s}\n", remaining_str); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		free(remaining_str); \
		token_mgr_del_inner(tokens); \
		token_mgr_del(tokens_list); \
		token_mgr_del(remaining_tokens); \
	}

mt_test_extract_assign(num1, "a=b echo a",    "a=b",      "echo_a",       false);
mt_test_extract_assign(num2, "=b echo a",      "",        "=b_echo_a",    false);
mt_test_extract_assign(num3, "a\\=b echo a",   "",        "a\\=b_echo_a", false);
mt_test_extract_assign(num4, "a=b",            "a=b",     "", 			  false);
mt_test_extract_assign(num5, "a= echo abc",    "a=",      "echo_abc",     false);
mt_test_extract_assign(num6, "a=1 b=2 c=3 echo abc d=4",
							 "a=1_b=2_c=3", "echo_abc_d=4", 			  false);

void	suite_token_mgr_extract_assignment(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
}
