#include "ast/nodes/ast_simple_command.h"
#include "builtin/builtin_mgr.h"
#include "data.h"
#include <project.h>

static void test_is_builtin(t_test *test)
{

	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "hello") == false);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "cd") == true);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "ls") == false);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "env") == true);
	mt_assert((bool)builtin_mgr_find_by_name(data_builtins(), "") == false);
}

static void test_get_binary_path(t_test *test)
{
	char *str;
	t_shenv *env;

	env = shenv_singleton();
	str = shenv_find_binary_path(env, "pouet");
	mt_assert( str == NULL);
	str = shenv_find_binary_path(env, "ls");
	mt_assert(str != NULL);
}

void	suite_check_command(t_suite *suite)
{

	SUITE_ADD_TEST(suite, test_is_builtin);
	SUITE_ADD_TEST(suite, test_get_binary_path);
}
