#include <project.h>

#include "edit/edit.h"

extern char	**environ;

static void test_edit_new(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();
	mt_assert(edit->index == 0);
	edit_del(edit);
}

static void test_edit_one_input_nl(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	cmd = edit_handle_one_input(edit, 10);
	mt_assert(strcmp(cmd, " ") == 0);
	mt_assert(edit->index == 0);
	edit_del(edit);
}

static void test_edit_one_input_four_input(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	cmd = edit_handle_one_input(edit, 42);
	cmd = edit_handle_one_input(edit, 42);
	cmd = edit_handle_one_input(edit, 42);
	cmd = edit_handle_one_input(edit, 42);
	mt_assert(cmd == NULL);
	if (cmd)
		free(cmd);
	mt_assert(edit->index == 4);
	edit_del(edit);
}

void	suite_edit_one_input(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_edit_new);
	SUITE_ADD_TEST(suite, test_edit_one_input_nl);
	SUITE_ADD_TEST(suite, test_edit_one_input_four_input);
}
