#include <project.h>

#include "edit/edit.h"

static t_edit	*init_edit_fn(char *last, char *cur, size_t pos)
{
	t_edit		*ret;
	ret = malloc(sizeof(t_edit));
	bzero(ret, sizeof(t_edit));
	ret->last_ps1 = last ? strdup(last) : last;
	ret->pos_cursor = pos;
	ret->current = line_new();
	ret->current->line = strdup(cur);
	ret->current->size = strlen(cur);
	ret->current->total = ret->current->size + 1;
	return (ret);
}

#define mt_edit_is_quoted_test(num, last, cur, pos, expected, debug)	\
static void		test_## num(t_test *test)								\
{																		\
	t_edit		*edit = init_edit_fn(last, cur, pos);					\
	bool		actual = edit_is_quoted(edit);							\
	if (debug)															\
	{																	\
		printf("last: %s", last ? last : "(null)\n");					\
		printf("current: %s\npos: %i\n", cur, pos);						\
		printf("actual: %s\n", actual ? "true" : "false");				\
		printf("expected: %s\n", expected ? "true" : "false");			\
	}																	\
	mt_assert(actual == expected);										\
	edit_del(edit);														\
}

mt_edit_is_quoted_test(num001, NULL, "012345", 0, false, false);
mt_edit_is_quoted_test(num002, NULL, "012345", 5, false, false);
mt_edit_is_quoted_test(num003, NULL, "''''''", 0, false, false);
mt_edit_is_quoted_test(num004, NULL, "''''''", 1, true, false);
mt_edit_is_quoted_test(num005, NULL, "''''''", 2, false, false);
mt_edit_is_quoted_test(num006, NULL, "''''''", 3, true, false);

mt_edit_is_quoted_test(num01, NULL, "012'45", 0, false, false);
mt_edit_is_quoted_test(num02, NULL, "012'45", 3, false, false);
mt_edit_is_quoted_test(num03, NULL, "012'45", 4, true, false);

mt_edit_is_quoted_test(num11, "lol '", "012'45", 0, true, false);
mt_edit_is_quoted_test(num12, "lol '", "012'45", 3, true, false);
mt_edit_is_quoted_test(num13, "lol '", "012'45", 4, false, false);

mt_edit_is_quoted_test(num21, "lol \\'", "012'45", 0, false, false);
mt_edit_is_quoted_test(num22, "lol \\'", "012'45", 3, false, false);
mt_edit_is_quoted_test(num23, "lol \\'", "012'45", 4, true, false);

mt_edit_is_quoted_test(num31, "lol '", "01\\'45", 0, true, false);
mt_edit_is_quoted_test(num32, "lol '", "01\\'45", 3, true, false);
mt_edit_is_quoted_test(num33, "lol '", "01\\'45", 4, false, false);

mt_edit_is_quoted_test(num41, "lol \\'", "01\\'45", 0, false, false);
mt_edit_is_quoted_test(num42, "lol \\'", "01\\'45", 3, false, false);
mt_edit_is_quoted_test(num43, "lol \\'", "01\\'45", 4, false, false);

void suite_edit_is_quoted(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num001);
	SUITE_ADD_TEST(suite, test_num002);
	SUITE_ADD_TEST(suite, test_num003);
	SUITE_ADD_TEST(suite, test_num004);
	SUITE_ADD_TEST(suite, test_num005);
	SUITE_ADD_TEST(suite, test_num006);

	SUITE_ADD_TEST(suite, test_num01);
	SUITE_ADD_TEST(suite, test_num02);
	SUITE_ADD_TEST(suite, test_num03);
                                    
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);

	SUITE_ADD_TEST(suite, test_num21);
	SUITE_ADD_TEST(suite, test_num22);
	SUITE_ADD_TEST(suite, test_num23);

	SUITE_ADD_TEST(suite, test_num31);
	SUITE_ADD_TEST(suite, test_num32);
	SUITE_ADD_TEST(suite, test_num33);

	SUITE_ADD_TEST(suite, test_num41);
	SUITE_ADD_TEST(suite, test_num42);
	SUITE_ADD_TEST(suite, test_num43);
}
