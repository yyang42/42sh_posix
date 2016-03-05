#include <project.h>

#include "token/token.h"
#include "token/token_type.h"

static void test_token_copy(t_test *test)
{
	t_token *token = token_new("my input", 12, 21);
	token->heredoc_text = twl_strdup("my heredoc");
	token->type = TOKEN_IO_NUMBER;
	t_token *copy = token_copy(token);
	mt_assert(strcmp(copy->text, "my input") == 0);
	mt_assert(strcmp(copy->heredoc_text, "my heredoc") == 0);
	mt_assert(copy->type == copy->type);
	mt_assert(copy->line == copy->line);
	mt_assert(copy->col == copy->col);
	token_del(token);
	token_del(copy);
}

void	suite_token_copy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_token_copy);
}
