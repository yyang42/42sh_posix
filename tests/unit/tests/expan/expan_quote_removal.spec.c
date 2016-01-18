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

	str = twl_strdup("sa\\lut\\lo\\l");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"salutlol") == 0);
	twl_strdel(&str);
}


static void quoted_simple_quote_test(t_test *test)
{
	char			*str;

	str = twl_strdup("salu\"\'\"tlol");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"salu\'tlol") == 0);
	twl_strdel(&str);
}

static void quoted_double_quote_test(t_test *test)
{
	char			*str;

	str = twl_strdup("salu\'\"\'tlol");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"salu\"tlol") == 0);
	twl_strdel(&str);
}

static void quoted_single_quote_backslash_test(t_test *test)
{
	char			*str;

	str = twl_strdup("lol\\\'po\\\'uet");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"lol'po'uet") == 0);
	twl_strdel(&str);
}

static void quoted_double_quote_backslash_test(t_test *test)
{
	char			*str;

	str = twl_strdup("lol\\\\\"po\\\\\"uet");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"lol\\po\\uet") == 0);
	twl_strdel(&str);
}

static void quoted_backslash_single_quote_test(t_test *test)
{
	char			*str;

	str = twl_strdup("lol\'\\po\'\\uet");
	expan_quote_removal(&str);
	mt_assert(twl_strcmp(str,"lol\\pouet") == 0);
	twl_strdel(&str);
}

static void simple_quote_hard_test(t_test *test)
{
	char			*str;

	str = twl_strdup("\'s\'a\'l\'u\'t\'lo\'l\'");
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
	SUITE_ADD_TEST(suite, quoted_simple_quote_test);
	SUITE_ADD_TEST(suite, quoted_double_quote_test);
	SUITE_ADD_TEST(suite, quoted_single_quote_backslash_test);
	SUITE_ADD_TEST(suite, quoted_double_quote_backslash_test);
	SUITE_ADD_TEST(suite, quoted_backslash_single_quote_test);
	SUITE_ADD_TEST(suite, simple_quote_hard_test);
}
