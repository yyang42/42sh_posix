#include <project.h>

#include "tokenizer.h"
#include "token_mgr.h"

static void simple(t_test *test)
{
	t_tokenizer		*tokenizer;
	char			*joined;

	tokenizer = tokenizer_new("aa\nbb");
	token_mgr_print(tokenizer->tokens);
	joined = token_mgr_strjoin(tokenizer->tokens);
	mt_assert(strcmp(joined, "aa bb") == 0);
	free(joined);
	tokenizer_del(tokenizer);
}

void	suite_tokenizer_rule7(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple);
}
