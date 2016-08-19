#include <project.h>

#include "edit/line.h"

#define mt_line_new_test(num, str, exp_tot, debug)				\
static void		test_## num(t_test *test)						\
{																\
	t_line		*line;											\
	line = line_new_from_string(str);							\
	if (debug)													\
	{															\
		printf("CASE: %s\n", str);								\
		printf("expected total: %zu\n", exp_tot);				\
		printf("actual total:   %zu\n", line->total);			\
	}															\
	mt_assert(strcmp(line->copy, str) == 0);					\
	mt_assert(strcmp(line->line, str) == 0);					\
	mt_assert(line->total == exp_tot);							\
	line_del(line);												\
}

mt_line_new_test(num01, "ls", 4ul, true);
mt_line_new_test(num02, "ls -la", 8ul, true);
mt_line_new_test(num03, "echo abc", 16ul, true);
mt_line_new_test(num04, "echo abc echo abcd", 32ul, true);

void suite_line_new_from_string(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
	SUITE_ADD_TEST(suite, test_num04);
}
