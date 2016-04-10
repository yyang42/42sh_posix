#include <project.h>

#include "expan/expan_tokenizer.h"

mt_test_expan(num01, "a~b", 0, "a~b", EXPAN_NONE, false)
mt_test_expan(num02, "~a~b", 0, "~a~b", EXPAN_TILDE, false)
mt_test_expan(num03, "~$a~b", 0, "~$a~b", EXPAN_TILDE, false)
mt_test_expan(num04, "~${a}`ls`$(ls)'ls'\"ls\"~b", 0,
							"~${a}`ls`$(ls)'ls'\"ls\"~b", EXPAN_TILDE, false)
mt_test_expan(num05, "~$((1/1))${a:-lol}/lol", 0, "~$((1/1))${a:-lol}", EXPAN_TILDE,
																		false)
mt_test_expan(num06, "~", 0, "~", EXPAN_TILDE, false);
mt_test_expan(num07, "~/", 0, "~", EXPAN_TILDE, false);
mt_test_expan(num08, "~/", 1, "/", EXPAN_NONE, false);
mt_test_expan(num09, "~loulilol/", 0, "~loulilol", EXPAN_TILDE, false);
mt_test_expan(num10, "~loulilol/pouf", 1, "/pouf", EXPAN_NONE, false);
mt_test_expan(num11, "~:", 0, "~", EXPAN_TILDE, false);
mt_test_expan(num12, "~:", 1, ":", EXPAN_NONE, false);
mt_test_expan(num13, "~loulilol:pouf", 0, "~loulilol", EXPAN_TILDE, false);
mt_test_expan(num14, "~loulilol:pouf", 1, ":pouf", EXPAN_NONE, false);
mt_test_expan(num15, "~loulilol:~pouf", 1, ":", EXPAN_NONE, false);
mt_test_expan(num16, "~loulilol:~pouf", 2, "~pouf", EXPAN_TILDE, false);

void suite_expan_tokenizer_rule02(t_suite *suite)
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
}
