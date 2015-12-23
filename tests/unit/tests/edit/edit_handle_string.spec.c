#include <project.h>

#include "edit/edit.h"

extern char	**environ;

static void test_simple_string_with_nl(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();

	cmd = edit_handle_string(edit, "bonjour\n");
	mt_assert(strcmp(cmd, "bonjour ") == 0);
	free(cmd);
	edit_del(edit);
}

static void test_simple_string_without_nl(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();

	cmd = edit_handle_string(edit, "bonjour");
	mt_assert(cmd == NULL);
	mt_assert(edit->index == 7);
	edit_del(edit);
}

void	suite_edit_handle_string(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_string_with_nl);
	SUITE_ADD_TEST(suite, test_simple_string_without_nl);
}
