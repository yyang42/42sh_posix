#include <project.h>

#include "edit/edit.h"

extern char	**environ;

static void test_backspace(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	edit_handle_string(edit, "Bonjour");
	edit_handle_one_input(edit, DELETE_KEY);
	cmd = edit_handle_one_input(edit, RETURN_KEY);
	mt_assert(strcmp(cmd, "Bonjou"));
	free(cmd);
	edit_del(edit);
}

static void test_backspace_empty_string(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	edit_handle_string(edit, "");
	edit_handle_one_input(edit, DELETE_KEY);
	edit_handle_one_input(edit, DELETE_KEY);
	cmd = edit_handle_one_input(edit, RETURN_KEY);
	mt_assert(strcmp(cmd, ""));
	free(cmd);
	edit_del(edit);
}

static void test_key_return(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	cmd = edit_handle_string(edit, "q");
	mt_assert(cmd == NULL);
	cmd = edit_handle_one_input(edit, RETURN_KEY);
	mt_assert(strcmp(cmd, "q"));
	free(cmd);
	edit_del(edit);
}

static void test_ctrl_d_empty_string(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	cmd = edit_handle_one_input(edit, CTRL_D);
	mt_assert(strcmp(cmd, "exit"));
	free(cmd);
	edit_del(edit);
}

static void test_ctrl_d_filled_string(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	edit_handle_string(edit, "q");
	cmd = edit_handle_one_input(edit, CTRL_D);
	mt_assert(cmd == NULL);
	edit_del(edit);
}

void	suite_edit_key_func(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_backspace);
	SUITE_ADD_TEST(suite, test_backspace_empty_string);
	SUITE_ADD_TEST(suite, test_key_return);
	SUITE_ADD_TEST(suite, test_ctrl_d_empty_string);
	SUITE_ADD_TEST(suite, test_ctrl_d_filled_string);
}
