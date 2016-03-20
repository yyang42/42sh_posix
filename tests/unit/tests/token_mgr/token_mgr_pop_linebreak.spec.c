#include <project.h>

#include "token/tokenizer.h"
#include "token/token_list_mgr.h"

# define mt_test_token_mgr_pop_linebreak(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens; \
		char			*joined_str; \
		tokens = tokenizer_utils_tokenize(input); \
		token_mgr_pop_linebreak(tokens); \
		joined_str = token_mgr_strjoin(tokens, "_"); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("actual   {%s}\n", joined_str); \
			twl_printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		token_mgr_del_inner(tokens); \
	}

mt_test_token_mgr_pop_linebreak(num1, "a b c", "a_b_c", false);
mt_test_token_mgr_pop_linebreak(num2, "\na b c", "a_b_c", false);
mt_test_token_mgr_pop_linebreak(num3, "\n\n\na b c", "a_b_c", false);
mt_test_token_mgr_pop_linebreak(num4, "a\nb c", "a_\n_b_c", false);

void	suite_token_mgr_pop_linebreak(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
}
