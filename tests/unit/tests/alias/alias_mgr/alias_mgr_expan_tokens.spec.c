#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"
#include "token/token_list_mgr.h"
#include "alias/alias_mgr.h"

# define mt_test_alias(test_name, input, expected, debug) \
	static void test_name(t_test *test) \
	{ \
		t_lst		*tokens; \
		t_htab		*aliases; \
		char		*joined; \
		aliases = twl_htab_new(); \
		twl_htab_set(aliases, "xxx", "echo", NULL); \
		twl_htab_set(aliases, "echo_space", "echo 1 ", NULL); \
		twl_htab_set(aliases, "multi", "echo abc", NULL); \
		twl_htab_set(aliases, "if", "shoud_not_expan_to_this", NULL); \
		twl_htab_set(aliases, "while", "shoud_not_expan_to_this", NULL); \
		tokens = tokenizer_utils_tokenize(input); \
		alias_mgr_expan_tokens(aliases, tokens, NULL); \
		joined = token_mgr_strjoin(tokens, "_"); \
		if (debug) \
		{ \
			printf("--------- %s ---------\n", #test_name); \
			printf("joined   : %s\n", joined); \
			printf("expected : %s\n", expected); \
		} \
		mt_assert(twl_strcmp(joined, expected) == 0); \
		token_mgr_del(tokens); \
		free(joined); \
	}

mt_test_alias(num1, "xxx abc", "echo_abc", false);
mt_test_alias(num2, "echo_space echo_space echo_space", "echo_1_echo_1_echo_1", false);
mt_test_alias(num3, "xxx abc && xxx 123", "echo_abc_&&_xxx_123", false);
mt_test_alias(no_expan, "(xxx abc)", "(_xxx_abc_)", false);
mt_test_alias(reserved, "if bla", "if_bla", false);
mt_test_alias(reserved2, "while bla", "while_bla", false);
mt_test_alias(expan_only_first, "xxx xxx", "echo_xxx", false);
mt_test_alias(multi_words, "multi 123", "echo_abc_123", false);

void	suite_alias_mgr_expan_tokens(t_suite *suite)
{
	SUITE_ADD_TEST(suite, num1);
	SUITE_ADD_TEST(suite, num2);
	SUITE_ADD_TEST(suite, num3);
	SUITE_ADD_TEST(suite, no_expan);
	SUITE_ADD_TEST(suite, reserved);
	SUITE_ADD_TEST(suite, reserved2);
	SUITE_ADD_TEST(suite, expan_only_first);
	SUITE_ADD_TEST(suite, multi_words);
}
