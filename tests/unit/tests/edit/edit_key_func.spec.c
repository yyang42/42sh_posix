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

static void test_ctrl_w_one_word(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	edit_handle_string(edit, "1 2 3");
	mt_assert(edit->index == 5);
	cmd = edit_handle_one_input(edit, CTRL_W);
	mt_assert(edit->index == 4);
	cmd = edit_handle_one_input(edit, RETURN_KEY);
	mt_assert(strcmp(cmd, "1 2  ") == 0);
	edit_del(edit);
}

static void test_ctrl_w_no_word(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	edit_handle_string(edit, "1");
	cmd = edit_handle_one_input(edit, CTRL_W);
	cmd = edit_handle_one_input(edit, RETURN_KEY);
	mt_assert(strcmp(cmd, " ") == 0);
	edit_del(edit);
}
static void test_delete_first_letter(t_test *test)
{
	t_edit			*edit;
	char			*cmd;

	edit = edit_new();
	edit_handle_string(edit, "123");
	mt_assert(edit->index == 3);
	cmd = edit_handle_one_input(edit, ARROW_LEFT);
	cmd = edit_handle_one_input(edit, ARROW_LEFT);
	mt_assert(edit->index == 1);
	cmd = edit_handle_one_input(edit, DELETE_KEY);
	mt_assert(edit->index == 0);
	cmd = edit_handle_one_input(edit, DELETE_KEY);
	mt_assert(edit->index == 0);
	edit_del(edit);
	(void)cmd;
}

void	suite_edit_key_func(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_backspace);
	SUITE_ADD_TEST(suite, test_backspace_empty_string);
	SUITE_ADD_TEST(suite, test_key_return);
	SUITE_ADD_TEST(suite, test_ctrl_d_empty_string);
	SUITE_ADD_TEST(suite, test_ctrl_d_filled_string);
	SUITE_ADD_TEST(suite, test_ctrl_w_one_word);
	SUITE_ADD_TEST(suite, test_ctrl_w_no_word);
	SUITE_ADD_TEST(suite, test_delete_first_letter);
}
