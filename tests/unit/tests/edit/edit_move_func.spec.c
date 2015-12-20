#include <project.h>

#include "edit/edit.h"

extern char	**environ;

static void test_move_left_two(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();

	edit_handle_string(edit, "bonjour");
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	mt_assert(edit->index == 5);
	edit_del(edit);
}

static void test_move_left_four(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();

	edit_handle_string(edit, "bon");
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	mt_assert(edit->index == 0);
	edit_del(edit);
}

void	suite_edit_move_func(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_move_left_two);
	SUITE_ADD_TEST(suite, test_move_left_four);
}
