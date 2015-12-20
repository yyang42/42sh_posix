#include <project.h>
#include "patmatch.h"

#define PATMATCH_TEST(str, nb, ret) {								\
	t_patmatch	*tmp = patmatch_new();								\
	t_lst		*lst = patmatch_match(tmp, str);					\
	dprintf(2, "%s %s\n", ret, twl_lst_get(lst, nb));	\
	if (ret == NULL) { mt_assert(twl_lst_get(lst, nb) == ret); }	\
	else { mt_assert(strcmp(twl_lst_get(lst, nb), ret) == 0); }		\
	twl_lst_del(lst, &free);										\
	patmatch_del(tmp);												\
}

static void	test_simple(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("sandbox/test0", 0, "sandbox/test0");
	PATMATCH_TEST("sandbox/test1", 0, "sandbox/test1");
	PATMATCH_TEST("sandbox/test2", 0, "sandbox/test2");
	PATMATCH_TEST("sandbox/.", 0, "sandbox/.");
	PATMATCH_TEST("sandbox", 0, "sandbox");
	PATMATCH_TEST("sandbox/", 0, "sandbox/");
	PATMATCH_TEST("sandbox/test3", 0, NULL);
}

static void	test_simple_asterisk(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("sandbox/*", 0, "sandbox/test0");
	PATMATCH_TEST("sandbox/*", 1, "sandbox/test1");
	PATMATCH_TEST("sandbox/*", 2, "sandbox/test2");
	PATMATCH_TEST("sandbox/*", 3, NULL);
}

static void	test_simple_question_mark(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("sandbox/test?", 0, "sandbox/test0");
	PATMATCH_TEST("sandbox/test?", 1, "sandbox/test1");
	PATMATCH_TEST("sandbox/test?", 2, "sandbox/test2");
	PATMATCH_TEST("sandbox/test?", 3, NULL);
}

static void	test_simple_bracket(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("sandbox/test[0123]", 0, "sandbox/test0");
	PATMATCH_TEST("sandbox/test[0123]", 1, "sandbox/test1");
	PATMATCH_TEST("sandbox/test[0123]", 2, "sandbox/test2");
	PATMATCH_TEST("sandbox/test[0123]", 3, NULL);
	PATMATCH_TEST("sandbox/test[0-3]", 0, "sandbox/test0");
	PATMATCH_TEST("sandbox/test[0-3]", 1, "sandbox/test1");
	PATMATCH_TEST("sandbox/test[0-3]", 2, "sandbox/test2");
	PATMATCH_TEST("sandbox/test[0-3]", 3, NULL);
	PATMATCH_TEST("sandbox/test[[:digit:]]", 0, "sandbox/test0");
	PATMATCH_TEST("sandbox/test[[:digit:]]", 1, "sandbox/test1");
	PATMATCH_TEST("sandbox/test[[:digit:]]", 2, "sandbox/test2");
	PATMATCH_TEST("sandbox/test[[:digit:]]", 3, NULL);
	PATMATCH_TEST("sandbox/test[^a-zA-Z]", 0, "sandbox/test0");
	PATMATCH_TEST("sandbox/test[^a-zA-Z]", 1, "sandbox/test1");
	PATMATCH_TEST("sandbox/test[^a-zA-Z]", 2, "sandbox/test2");
	PATMATCH_TEST("sandbox/test[^a-zA-Z]", 3, NULL);
}

static void	test_middle_asterisk(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("mkdir test0 test1 test2 .test0 .test1 .test2 && "\
				"touch test{0..2}/test1 .test{0..2}/test2 testnul && "\
				"ln -s test0 test3");
	PATMATCH_TEST("sandbox/*/*", 0, "sandbox/test0/test1");
	PATMATCH_TEST("sandbox/*/*", 1, "sandbox/test1/test1");
	PATMATCH_TEST("sandbox/*/*", 2, "sandbox/test2/test1");
	PATMATCH_TEST("sandbox/*/*", 3, "sandbox/test3/test1");
	PATMATCH_TEST("sandbox/*/*", 4, NULL); 
	PATMATCH_TEST("sandbox/.*/t*2", 0, "sandbox/.test0/test2");
	PATMATCH_TEST("sandbox/.*/t*2", 1, "sandbox/.test1/test2");
	PATMATCH_TEST("sandbox/.*/t*2", 2, "sandbox/.test2/test2");
	PATMATCH_TEST("sandbox/.*/t*2", 3, NULL); 
}

static void	test_middle_question_mark(t_test *test)
{
	(void)test;
}

static void	test_middle_bracket(t_test *test)
{
	(void)test;
}

void		suite_patmatch_match(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_simple_asterisk);
	SUITE_ADD_TEST(suite, test_simple_question_mark);
	SUITE_ADD_TEST(suite, test_simple_bracket);
	SUITE_ADD_TEST(suite, test_middle_asterisk);
	SUITE_ADD_TEST(suite, test_middle_question_mark);
	SUITE_ADD_TEST(suite, test_middle_bracket);
}
