#include <project.h>

#include "basics.h"
#include "environment.h"
#include "ast/expan/ast_expan_quote_removal.h"

static void simple_quote_test(t_test *test)
{
	char			*str;

	str = twl_strdup("salut\'lol\'");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"salutlol") == 0);
	twl_strdel(&str);
}

static void double_quote_test(t_test *test)
{
	char			*str;

	str = twl_strdup("salut\"lol\"");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"salutlol") == 0);
	twl_strdel(&str);
}

static void backslash_test(t_test *test)
{
	char			*str;

	str = twl_strdup("salut\\lo\\l");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"salutlol") == 0);
	twl_strdel(&str);
}

void	suite_expan_quote_removal(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_quote_test);
	SUITE_ADD_TEST(suite, double_quote_test);
	SUITE_ADD_TEST(suite, backslash_test);
}
