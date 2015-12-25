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

static void test_move_left_right_one(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();

	edit_handle_string(edit, "bonj");
	edit_handle_one_input(edit, ARROW_LEFT);
	mt_assert(edit->index == 3);
	edit_handle_one_input(edit, ARROW_RIGHT);
	mt_assert(edit->index == 4);
	edit_del(edit);
}

static void test_move_left_max(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();

	edit_handle_string(edit, "1");
	mt_assert(edit->index == 1);
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	edit_handle_one_input(edit, ARROW_LEFT);
	mt_assert(edit->index == 0);
	edit_del(edit);
}

static void test_move_right_max(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();

	edit_handle_string(edit, "1");
	mt_assert(edit->index == 1);
	edit_handle_one_input(edit, ARROW_RIGHT);
	edit_handle_one_input(edit, ARROW_RIGHT);
	edit_handle_one_input(edit, ARROW_RIGHT);
	edit_handle_one_input(edit, ARROW_RIGHT);
	edit_handle_one_input(edit, ARROW_RIGHT);
	mt_assert(edit->index == 1);
	edit_del(edit);
}

static void test_move_begin(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();

	edit_handle_string(edit, "1234567");
	mt_assert(edit->index == 7);
	edit_handle_one_input(edit, CTRL_A);
	mt_assert(edit->index == 0);
	edit_del(edit);
}

static void test_move_end(t_test *test)
{
	t_edit			*edit;

	edit = edit_new();

	edit_handle_string(edit, "1234567");
	mt_assert(edit->index == 7);
	edit_handle_one_input(edit, CTRL_A);
	mt_assert(edit->index == 0);
	edit_handle_one_input(edit, CTRL_E);
	mt_assert(edit->index == 7);
	edit_del(edit);
}

void	suite_edit_move_func(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_move_left_two);
	SUITE_ADD_TEST(suite, test_move_left_four);
	SUITE_ADD_TEST(suite, test_move_left_right_one);
	SUITE_ADD_TEST(suite, test_move_left_max);
	SUITE_ADD_TEST(suite, test_move_right_max);
	SUITE_ADD_TEST(suite, test_move_begin);
	SUITE_ADD_TEST(suite, test_move_end);
}
