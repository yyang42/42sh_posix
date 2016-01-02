#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"
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
		openclose_matcher_add(matcher, "while", "done"); \
		tokens = tokenizer_tokenize(input); \
		pos = openclose_matcher_token_find_matching(matcher, tokens); \
		if (pos > 0) \
			slice = twl_lst_slice(tokens, pos, twl_lst_len(tokens)); \
		else \
			slice = twl_lst_new(); \
		char *res = token_mgr_strjoin(slice); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			printf("pos    : %d\n", pos); \
			printf("actual   {%s}\n", res); \
			printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(res, expected) == 0); \
		openclose_matcher_del(matcher); \
		free(res); \
	}

mt_test_openclose_token(num1, "(a1 ; a3) > file", ">_file", false);
mt_test_openclose_token(num2, "if true; then (echo abc); fi ; abc", ";_abc", false);
mt_test_openclose_token(num3, "( ( ( echo a ) ) ) > 123", ">_123", false);
mt_test_openclose_token(num4, "abc", "", false);
mt_test_openclose_token(num5, "abc 123", "", false);
mt_test_openclose_token(num6, "while true; do abc; done ; abc", ";_abc", false);
mt_test_openclose_token(num7, "while true; do abc; while false; do echo a; done; done ; abc", ";_abc", false);

void	suite_openclose_matcher_token_find_matching(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
}
