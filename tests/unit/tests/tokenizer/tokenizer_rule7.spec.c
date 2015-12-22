#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

static void simple(t_test *test)
{
	t_tokenizer		*tokenizer;
	char			*joined;

	tokenizer = tokenizer_new("aa\nbb");
	// token_mgr_print(tokenizer->tokens);
	joined = token_mgr_strjoin(tokenizer->tokens);
	mt_assert(strcmp(joined, "aa bb") == 0);
	free(joined);
	tokenizer_del(tokenizer);
}

static void simple2(t_test *test)
{
	t_tokenizer		*tokenizer;
	char			*joined;

	tokenizer = tokenizer_new("aa\n\nbb");
	// token_mgr_print(tokenizer->tokens);
	joined = token_mgr_strjoin(tokenizer->tokens);
	mt_assert(strcmp(joined, "aa bb") == 0);
	free(joined);
	tokenizer_del(tokenizer);
}

static void simple3(t_test *test)
{
	t_tokenizer		*tokenizer;
	char			*joined;

	tokenizer = tokenizer_new("\naa\n\nbb");
	// token_mgr_print(tokenizer->tokens);
	joined = token_mgr_strjoin(tokenizer->tokens);
	mt_assert(strcmp(joined, "aa bb") == 0);
	free(joined);
	tokenizer_del(tokenizer);
}

static void simple4(t_test *test)
{
	t_tokenizer		*tokenizer;
	char			*joined;

	tokenizer = tokenizer_new("aa\n\nbb\n");
	// token_mgr_print(tokenizer->tokens);
	joined = token_mgr_strjoin(tokenizer->tokens);
	mt_assert(strcmp(joined, "aa bb") == 0);
	free(joined);
	tokenizer_del(tokenizer);
}


static void simple5(t_test *test)
{
	t_tokenizer		*tokenizer;
	char			*joined;

	tokenizer = tokenizer_new("\n\n\naa\n\nbb\n\n\n");
	// token_mgr_print(tokenizer->tokens);
	joined = token_mgr_strjoin(tokenizer->tokens);
	mt_assert(strcmp(joined, "aa bb") == 0);
	free(joined);
	tokenizer_del(tokenizer);
}

static void only_newlines(t_test *test)
{
	t_tokenizer		*tokenizer;
	char			*joined;

	tokenizer = tokenizer_new("\n\n\n");
	// token_mgr_print(tokenizer->tokens);
	joined = token_mgr_strjoin(tokenizer->tokens);
	mt_assert(strcmp(joined, "") == 0);
	free(joined);
	tokenizer_del(tokenizer);
}

void	suite_tokenizer_rule7(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
	SUITE_ADD_TEST(suite, simple2);
	SUITE_ADD_TEST(suite, simple3);
	SUITE_ADD_TEST(suite, simple4);
	SUITE_ADD_TEST(suite, simple5);
	SUITE_ADD_TEST(suite, only_newlines);
}
