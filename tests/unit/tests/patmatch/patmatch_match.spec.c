#include <project.h>
#include "patmatch.h"

#define PATMATCH_TEST(str, nb, sret) {								\
	t_patmatch	*tmp = patmatch_new();								\
	t_lst		*lst = patmatch_match(tmp, str);					\
	char		*ret = sret;										\
	if (ret == NULL) { mt_assert(twl_lst_get(lst, nb) == ret); }	\
	else { mt_assert(strcmp(twl_lst_get(lst, nb), ret) == 0); }		\
	twl_lst_del(lst, &free);										\
	patmatch_del(tmp);												\
}

static void	test_simple(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("/tmp/sandbox/test0", 0, "/tmp/sandbox/test0");
	PATMATCH_TEST("/tmp/sandbox/test1", 0, "/tmp/sandbox/test1");
	PATMATCH_TEST("/tmp/sandbox/test2", 0, "/tmp/sandbox/test2");
	PATMATCH_TEST("/tmp/sandbox/.", 0, "/tmp/sandbox/.");
	PATMATCH_TEST("/tmp/sandbox", 0, "/tmp/sandbox");
	PATMATCH_TEST("/tmp/sandbox/", 0, "/tmp/sandbox/");
	PATMATCH_TEST("/tmp/sandbox/test3", 0, "/tmp/sandbox/test3");
}

static void	test_simple_asterisk(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("/tmp/sandbox/*", 0, "/tmp/sandbox/test0");
	PATMATCH_TEST("/tmp/sandbox/*", 1, "/tmp/sandbox/test1");
	PATMATCH_TEST("/tmp/sandbox/*", 2, "/tmp/sandbox/test2");
	PATMATCH_TEST("/tmp/sandbox/*", 3, NULL);
}

static void	test_simple_question_mark(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("/tmp/sandbox/test?", 0, "/tmp/sandbox/test0");
	PATMATCH_TEST("/tmp/sandbox/test?", 1, "/tmp/sandbox/test1");
	PATMATCH_TEST("/tmp/sandbox/test?", 2, "/tmp/sandbox/test2");
	PATMATCH_TEST("/tmp/sandbox/test?", 3, NULL);
}

static void	test_simple_bracket(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch test0 test1 test2");
	PATMATCH_TEST("/tmp/sandbox/test[0123]", 0, "/tmp/sandbox/test0");
	PATMATCH_TEST("/tmp/sandbox/test[0123]", 1, "/tmp/sandbox/test1");
	PATMATCH_TEST("/tmp/sandbox/test[0123]", 2, "/tmp/sandbox/test2");
	PATMATCH_TEST("/tmp/sandbox/test[0123]", 3, NULL);
	PATMATCH_TEST("/tmp/sandbox/test[0-3]", 0, "/tmp/sandbox/test0");
	PATMATCH_TEST("/tmp/sandbox/test[0-3]", 1, "/tmp/sandbox/test1");
	PATMATCH_TEST("/tmp/sandbox/test[0-3]", 2, "/tmp/sandbox/test2");
	PATMATCH_TEST("/tmp/sandbox/test[0-3]", 3, NULL);
	PATMATCH_TEST("/tmp/sandbox/test[[:digit:]]", 0, "/tmp/sandbox/test0");
	PATMATCH_TEST("/tmp/sandbox/test[[:digit:]]", 1, "/tmp/sandbox/test1");
	PATMATCH_TEST("/tmp/sandbox/test[[:digit:]]", 2, "/tmp/sandbox/test2");
	PATMATCH_TEST("/tmp/sandbox/test[[:digit:]]", 3, NULL);
	PATMATCH_TEST("/tmp/sandbox/test[^a-zA-Z]", 0, "/tmp/sandbox/test0");
	PATMATCH_TEST("/tmp/sandbox/test[^a-zA-Z]", 1, "/tmp/sandbox/test1");
	PATMATCH_TEST("/tmp/sandbox/test[^a-zA-Z]", 2, "/tmp/sandbox/test2");
	PATMATCH_TEST("/tmp/sandbox/test[^a-zA-Z]", 3, NULL);
}

static void	test_middle_asterisk(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("mkdir test0 test1 test2 .test0 .test1 && "\
				"touch test0/test1 test1/test1 && "\
				"touch .test0/test2 .test1/test2 testnul && "\
				"ln -s test0 test3");
	PATMATCH_TEST("/tmp/sandbox/*/*", 0, "/tmp/sandbox/test0/test1");
	PATMATCH_TEST("/tmp/sandbox/*/*", 1, "/tmp/sandbox/test1/test1");
	PATMATCH_TEST("/tmp/sandbox/*/*", 2, "/tmp/sandbox/test3/test1");
	PATMATCH_TEST("/tmp/sandbox/*/*", 3, NULL); 
	PATMATCH_TEST("/tmp/sandbox/.*/t*2", 0, "/tmp/sandbox/./test2");
	PATMATCH_TEST("/tmp/sandbox/.*/t*2", 1, "/tmp/sandbox/.test0/test2");
	PATMATCH_TEST("/tmp/sandbox/.*/t*2", 2, "/tmp/sandbox/.test1/test2");
	PATMATCH_TEST("/tmp/sandbox/.*/t*2", 3, NULL); 
	PATMATCH_TEST("\"/tmp/sandbox/.*/t*2\"", 0, "/tmp/sandbox/.*/t*2");
}

static void	test_middle_question_mark(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch aaa bbb ccc abc");
	PATMATCH_TEST("/tmp/sandbox/???", 0, "/tmp/sandbox/aaa");
	PATMATCH_TEST("/tmp/sandbox/???", 1, "/tmp/sandbox/abc");
	PATMATCH_TEST("/tmp/sandbox/???", 2, "/tmp/sandbox/bbb");
	PATMATCH_TEST("/tmp/sandbox/???", 3, "/tmp/sandbox/ccc");
	PATMATCH_TEST("/tmp/sandbox/???", 4, NULL);
//	PATMATCH_TEST("/tmp/sandbox/?b?", 0, "/tmp/sandbox/abc");
//	PATMATCH_TEST("/tmp/sandbox/?b?", 1, "/tmp/sandbox/bbb");
//	PATMATCH_TEST("/tmp/sandbox/?b?", 2, NULL);
//	PATMATCH_TEST("/tmp/sandbox/????", 0, "/tmp/sandbox/????");
//	PATMATCH_TEST("/tmp/sandbox/????", 1, NULL);
}

static void	test_middle_bracket(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("touch -- 1aZ a1Z 1Za Z1a aZ1 Za1 -Z1");
	PATMATCH_TEST("/tmp/sandbox/[aze][AZE][123]", 0, "/tmp/sandbox/aZ1");
	PATMATCH_TEST("/tmp/sandbox/[aze][AZE][123]", 1, NULL);
	PATMATCH_TEST("/tmp/sandbox/[a-z][A-Z][0-9]", 0, "/tmp/sandbox/aZ1");
	PATMATCH_TEST("/tmp/sandbox/[a-z][A-Z][0-9]", 1, NULL);
	PATMATCH_TEST("/tmp/sandbox/[[:lower:]][[:upper:]][[:digit:]]", 0, "/tmp/sandbox/aZ1");
	PATMATCH_TEST("/tmp/sandbox/[[:lower:]][[:upper:]][[:digit:]]", 1, NULL);
	PATMATCH_TEST("/tmp/sandbox/[aze[:lower:]a-z-][[:upper:]][[:digit:]]", 0, "/tmp/sandbox/-Z1");
	PATMATCH_TEST("/tmp/sandbox/[aze[:lower:]a-z-][[:upper:]][[:digit:]]", 1, "/tmp/sandbox/aZ1");
	PATMATCH_TEST("/tmp/sandbox/[aze[:lower:]a-z-][[:upper:]][[:digit:]]", 2, NULL);
	PATMATCH_TEST("/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:]]", 0, "/tmp/sandbox/a1Z");
	PATMATCH_TEST("/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:]]", 1, "/tmp/sandbox/Z1a");
	PATMATCH_TEST("/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:]]", 2, NULL);
	PATMATCH_TEST("/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:][:alpha:]]",
			0, "/tmp/sandbox/[^ze[:digit:]z-a-][^[:upper:]][^[:digit:][:alpha:]]");
}

static void	test_melting_pot(t_test *test)
{
	reset_sandbox();
	sandbox_cmd("mkdir -p test0/test0 test0/test5 test1/test0 test2/test0 "\
				"test3/test0 test4/test0 test5/test0 test5/test5 && "\
				"ln -s test0/test5 test6 && "\
				"touch test0/test5/pouf");
	PATMATCH_TEST("/tmp/sandbox/*[[:digit:]]/???*[^[:digit:]]", 0, "/tmp/sandbox/test6/pouf");
	PATMATCH_TEST("/tmp/sandbox/*[[:digit:]]/???*[^[:digit:]]", 1, NULL);
	PATMATCH_TEST("/tmp/sandbox/*?[[:lower:]]?[[:digit:]]*"\
			"/*?[[:lower:]]?[[:digit:]]*/**?**?**?**?**",
			0, "/tmp/sandbox/test0/test5/pouf");
	PATMATCH_TEST("/tmp/sandbox/*?[[:lower:]]?[[:digit:]]*"\
			"/*?[[:lower:]]?[[:digit:]]*/**?**?**?**?**/",
			0, "/tmp/sandbox/*?[[:lower:]]?[[:digit:]]*"\
			"/*?[[:lower:]]?[[:digit:]]*/**?**?**?**?**/");
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
	SUITE_ADD_TEST(suite, test_melting_pot);
}
