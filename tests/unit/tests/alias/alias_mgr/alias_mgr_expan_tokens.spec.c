#include <project.h>

#include "token/tokenizer.h"
#include "token/token_mgr.h"
#include "token/token_list_mgr.h"
#include "alias/alias_mgr.h"

# define mt_test_alias(test_name, input, expected, debug) \
	static void test_name(t_test *test) \
	{ \
		t_lst		*tokens; \
		t_lst		*expanded_tokens; \
		t_htab		*aliases; \
		char		*joined; \
		aliases = twl_htab_new(); \
		twl_htab_set(aliases, "xxx", "echo", NULL); \
		twl_htab_set(aliases, "multi", "echo abc", NULL); \
		tokens = tokenizer_utils_tokenize(input); \
		expanded_tokens = alias_mgr_expan_tokens(aliases, tokens); \
		joined = token_mgr_strjoin(expanded_tokens, "_"); \
		if (debug) \
		{ \
			printf("--------- %s ---------\n", #test_name); \
			printf("joined   : %s\n", joined); \
			printf("expected : %s\n", expected); \
		} \
		mt_assert(twl_strcmp(joined, expected) == 0); \
		token_mgr_del(tokens); \
		token_mgr_del(expanded_tokens); \
		free(joined); \
	}

mt_test_alias(num1, "xxx abc", "echo_abc", false);
mt_test_alias(num2, "xxx abc;xxx 123", "echo_abc_;_echo_123", false);
mt_test_alias(num3, "xxx abc && xxx 123", "echo_abc_&&_echo_123", false);
mt_test_alias(subshell, "(xxx abc)", "(_echo_abc_)", false);
mt_test_alias(bracegroup, "{ xxx abc; }", "{_echo_abc_;_}", false);
mt_test_alias(reserved, "if xxx abc; then xxx a; xxx b; fi", "if_echo_abc_;_then_echo_a_;_echo_b_;_fi", false);
mt_test_alias(expan_only_first, "xxx xxx", "echo_xxx", false);
mt_test_alias(multi_words, "multi 123", "echo_abc_123", false);
// mt_test_alias(trailing_space, "space space space abc", "echo_a_echo_a_echo_a_abc", false);

void	suite_alias_mgr_expan_tokens(t_suite *suite)
{
	SUITE_ADD_TEST(suite, num1);
	SUITE_ADD_TEST(suite, num2);
	SUITE_ADD_TEST(suite, num3);
	SUITE_ADD_TEST(suite, subshell);
	SUITE_ADD_TEST(suite, bracegroup);
	SUITE_ADD_TEST(suite, reserved);
	SUITE_ADD_TEST(suite, expan_only_first);
	SUITE_ADD_TEST(suite, multi_words);
	// SUITE_ADD_TEST(suite, trailing_space);
}
