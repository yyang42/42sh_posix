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

	edit_del(edit);
}

void	suite_edit_move_func(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
}
