#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"
#include "openclose_matcher.h"

# define mt_test_openclose_token(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_openclose_matcher		*matcher; \
		int						pos; \
		t_lst					*tokens; \
		t_lst					*slice; \
		matcher = openclose_matcher_new(); \
		openclose_matcher_add(matcher, "(", ")"); \
		openclose_matcher_add(matcher, "if", "fi"); \
		tokens = tokenizer_tokenize(input); \
		pos = openclose_matcher_token_find_matching(matcher, tokens); \
		if (pos > 0) \
			slice = twl_lst_slice(tokens, pos, twl_lst_len(tokens)); \
		else \
			slice = twl_lst_new(); \
		char *res = token_mgr_strjoin(slice); \
		if (debug) \
		{ \
			printf("actual   {%s}\n", res); \
			printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(res, expected) == 0); \
		openclose_matcher_del(matcher); \
		free(res); \
	}

mt_test_openclose_token(num1, "(a1 ; a3) > file", ">_file", true);
mt_test_openclose_token(num2, "if true; then (echo abc); fi ; abc", ";_abc", true);
mt_test_openclose_token(num3, "( ( ( echo a ) ) ) > 123", ">_123", true);
mt_test_openclose_token(num4, "abc", "", true);

void	suite_openclose_matcher_token_find_matching(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	// SUITE_ADD_TEST(suite, test_num11);

	// SUITE_ADD_TEST(suite, test_equal1);
	// SUITE_ADD_TEST(suite, test_equal2);
	// SUITE_ADD_TEST(suite, test_equal3);
}
