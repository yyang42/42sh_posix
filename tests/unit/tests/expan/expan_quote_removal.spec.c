#include <project.h>

#include "basics.h"
#include "environment.h"
#include "ast/expan/ast_expan_quote_removal.h"

static void simple_quote_test(t_test *test)
{
	char			*str;

	str = twl_strdup("salut\'lol\'");
	twl_printf("BEFORE : %s\n", str);
	expan_quote_removal(&str);
	twl_printf("AFTER : %s\n", str);
	mt_assert(twl_strcmp(str,"salutlol") == 0);
	twl_strdel(&str);
}

void	suite_expan_quote_removal(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, simple_quote_test);
}
