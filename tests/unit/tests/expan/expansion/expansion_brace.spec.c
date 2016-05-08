#include <project.h>

#include "expan/expansion_parameter_brace.h"

char		*g_null = NULL;

#define mt_expansion_brace_test(num, input,	exp_param, exp_word, exp_err,		\
															exp_type, debug)	\
static void		test_## num(t_test *test)										\
{																				\
	t_expansion_brace	*eb = expansion_brace_new(input);						\
	if (debug)																	\
	{																			\
		twl_printf("  input:    %s\n", input);									\
		twl_printf("  actual:   param %s || word %s || error %s\n",				\
				eb->param, eb->word, eb->error);								\
		twl_printf("  expected: param %s || word %s || error %s\n",				\
				exp_param, exp_word, exp_err);									\
	}																			\
	if (!exp_param) { mt_assert(eb->param == NULL); }							\
	else { mt_assert(strcmp(eb->param, exp_param) == 0); }						\
	if (!exp_word) { mt_assert(eb->word == NULL); }								\
	else { mt_assert(strcmp(eb->word, exp_word) == 0); }						\
	if (!exp_err) { mt_assert(eb->error == NULL); }								\
	else { mt_assert(strcmp(eb->error, exp_err) == 0); }						\
	mt_assert(eb->type == exp_type);											\
	expansion_brace_del(eb);													\
}

//mt_expansion_brace_test(num, "${}", , , , BRACE_, false)
mt_expansion_brace_test(num01, "${}", g_null, g_null, "${}: bad substitution", BRACE_ERROR, false)
mt_expansion_brace_test(num02, "${a}", "a", g_null, g_null, BRACE_NONE, false)
mt_expansion_brace_test(num03, "${#}", "#", g_null, g_null, BRACE_NONE, false)
mt_expansion_brace_test(num04, "${##}", "#", g_null, g_null, BRACE_LENGTH, false)
mt_expansion_brace_test(num05, "${###}", "#", "", g_null, BRACE_SHARP_SHARP, false)
mt_expansion_brace_test(num06, "${####}", "#", "#", g_null, BRACE_SHARP_SHARP, false)
mt_expansion_brace_test(num07, "${a`lol`}", g_null, g_null, "${a`lol`}: bad substitution", BRACE_ERROR, false)
mt_expansion_brace_test(num08, "${@a}", g_null, g_null, "${@a}: bad substitution", BRACE_ERROR, false)
mt_expansion_brace_test(num09, "${#abc}", "abc", g_null, g_null, BRACE_LENGTH, false)
mt_expansion_brace_test(num10, "${#12ab}", g_null, g_null, "${#12ab}: bad substitution", BRACE_ERROR, false)
mt_expansion_brace_test(num11, "${12ab}", g_null, g_null, "${12ab}: bad substitution", BRACE_ERROR, false)
mt_expansion_brace_test(num12, "${a:b}", "a", g_null, "${a:b}: syntax error: operand expected", BRACE_ERROR, false)
mt_expansion_brace_test(num13, "${a-$(ls)}", "a", "$(ls)", g_null, BRACE_HYPHEN, false)
mt_expansion_brace_test(num14, "${a=$(ls)}", "a", "$(ls)", g_null, BRACE_EQUAL, false)
mt_expansion_brace_test(num15, "${a?$(ls)}", "a", "$(ls)", g_null, BRACE_QMARK, false)
mt_expansion_brace_test(num16, "${a+$(ls)}", "a", "$(ls)", g_null, BRACE_PLUS, false)
mt_expansion_brace_test(num17, "${a:-$(ls)}", "a", "$(ls)", g_null, BRACE_COLON_HYPHEN, false)
mt_expansion_brace_test(num18, "${a:=$(ls)}", "a", "$(ls)", g_null, BRACE_COLON_EQUAL, false)
mt_expansion_brace_test(num19, "${a:?$(ls)}", "a", "$(ls)", g_null, BRACE_COLON_QMARK, false)
mt_expansion_brace_test(num20, "${a:+$(ls)}", "a", "$(ls)", g_null, BRACE_COLON_PLUS, false)
mt_expansion_brace_test(num21, "${abc%l*o*l}", "abc", "l*o*l", g_null, BRACE_PERCENT, false)
mt_expansion_brace_test(num22, "${abc#l*o*l}", "abc", "l*o*l", g_null, BRACE_SHARP, false)
mt_expansion_brace_test(num23, "${abc%%l*o*l}", "abc", "l*o*l", g_null, BRACE_PERCENT_PERCENT, false)
mt_expansion_brace_test(num24, "${abc##l*o*l}", "abc", "l*o*l", g_null, BRACE_SHARP_SHARP, false)
mt_expansion_brace_test(num25, "${pouet:-}", "pouet", "", g_null, BRACE_COLON_HYPHEN, false)
mt_expansion_brace_test(num26, "${123#}", "123", "", g_null, BRACE_SHARP, false)
mt_expansion_brace_test(num27, "${#:?#}", "#", "#", g_null, BRACE_COLON_QMARK, false)
mt_expansion_brace_test(num28, "${:+}", g_null, g_null, "${:+}: bad substitution", BRACE_ERROR, false)
mt_expansion_brace_test(num29, "${@=pouet}", "@", g_null, "${@=pouet}: cannot assign in this way", BRACE_ERROR, false)
mt_expansion_brace_test(num30, "${12:=lol}", "12", g_null, "${12:=lol}: cannot assign in this way", BRACE_ERROR, false)

void suite_expansion_brace(t_suite *suite)
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
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_num14);
	SUITE_ADD_TEST(suite, test_num15);
	SUITE_ADD_TEST(suite, test_num16);
	SUITE_ADD_TEST(suite, test_num17);
	SUITE_ADD_TEST(suite, test_num18);
	SUITE_ADD_TEST(suite, test_num19);
	SUITE_ADD_TEST(suite, test_num20);
	SUITE_ADD_TEST(suite, test_num21);
	SUITE_ADD_TEST(suite, test_num22);
	SUITE_ADD_TEST(suite, test_num23);
	SUITE_ADD_TEST(suite, test_num24);
	SUITE_ADD_TEST(suite, test_num25);
	SUITE_ADD_TEST(suite, test_num26);
	SUITE_ADD_TEST(suite, test_num27);
	SUITE_ADD_TEST(suite, test_num28);
	SUITE_ADD_TEST(suite, test_num29);
	SUITE_ADD_TEST(suite, test_num30);
}
