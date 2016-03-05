#include "ast/nodes/ast_simple_command.h"
#include "builtin/builtin_mgr.h"
#include "data.h"
#include <project.h>

static void test_is_builtin(t_test *test)
{
	(void)test;
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "hello") == false);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "cd") == true);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "ls") == false);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "env") == true);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "") == false);
}

static void test_get_binary_path(t_test *test)
{
	(void)test;
	char *str;
	t_shenv *env;

	env = shenv_singleton();
	str = ast_simple_command_utils_get_binary_path("pouet", env);
	mt_assert( str == NULL);
	str = ast_simple_command_utils_get_binary_path("ls", env);
	mt_assert(str != NULL);
	twl_strdel(&str);
	shenv_del(env);
}

void	suite_check_command(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, test_is_builtin);
	SUITE_ADD_TEST(suite, test_get_binary_path);
}
