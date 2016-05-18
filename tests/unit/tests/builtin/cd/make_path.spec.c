#include <project.h>

#include "builtin/cmds/builtin_cd.h"

# define mt_test_make_path(test_name, path, dir, expected, debug)	\
static void test_## test_name(t_test *test)							\
{																	\
	char	*actual = builtin_cd_make_path_from_dir(path, dir);		\
	if (debug)														\
	{																\
		printf("case ======\n");									\
		printf("dir      : %s\n", dir);								\
		printf("path     : %s\n", path);							\
		printf("actual   : %s\n", actual);							\
		printf("expected : %s\n", expected);						\
	}																\
	mt_assert(strcmp(actual, expected) == 0);						\
	free(actual);													\
}

mt_test_make_path(num01, "/", ".", "/.", false);
mt_test_make_path(num02, "/", "..", "/..", false);
mt_test_make_path(num03, "//", ".", "//.", false);
mt_test_make_path(num04, "//", "..", "//..", false);
mt_test_make_path(num05, "///", ".", "///.", false);
mt_test_make_path(num06, "///", "..", "///..", false);

mt_test_make_path(num07, "/tmp/pouet", "lel//../lel/.//./..///pouet/../../tmp", 
					"/tmp/pouet/lel//../lel/.//./..///pouet/../../tmp", false)
mt_test_make_path(num08, "//tmp///pouet", "lel//../lel/.//./..///pouet/../../tmp", 
					"//tmp///pouet/lel//../lel/.//./..///pouet/../../tmp", false)
mt_test_make_path(num09, "/tmp", "/silly", "/silly", false);

void			suite_make_path(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
	SUITE_ADD_TEST(suite, test_num05);
	SUITE_ADD_TEST(suite, test_num06);
	SUITE_ADD_TEST(suite, test_num07);
	SUITE_ADD_TEST(suite, test_num08);
	SUITE_ADD_TEST(suite, test_num09);
}
