#include <project.h>
#include "pattern_matching/pattern.h"

#define mt_test_pattern_tostring(test_name, input, expected, debug)	\
static void test_## test_name(t_test *test)							\
{																	\
	t_pattern	*tmp = pattern_new(input);							\
	char		*actual = pattern_to_string(tmp);					\
	if (debug)														\
	{																\
		printf("=== case %s\n", input);								\
		printf("actual   -> %s\n", actual);							\
		printf("expected -> %s\n", expected);						\
	}																\
	mt_assert(strcmp(actual, expected) == 0);						\
	pattern_del(tmp);												\
	free(actual);													\
}

mt_test_pattern_tostring(num1, "[]", "[]", false);
mt_test_pattern_tostring(num2, "[\\[\\]]", "[[]]", false);
mt_test_pattern_tostring(num3, "[[:digit:]]", "[[:digit:]]", false);
mt_test_pattern_tostring(num4, "[a[:digit:]e[=a=]i[.ch.]o[:alnum:]u\\[\\]y]", "[a[:digit:]e[=a=]i[.ch.]o[:alnum:]u[]y]", false);
mt_test_pattern_tostring(num5, "[\"'\"]['\"']", "[\"'\"]['\"']", false);
mt_test_pattern_tostring(num6, "Makefil[[:helo]]test", "Makefil[[:helo]]test", false);
mt_test_pattern_tostring(num7, "*?k[AEIOU[:lower:]]**'f'\"i\"le", "*?k[AEIOU[:lower:]]**file", false);
mt_test_pattern_tostring(num8, "SALUT", "SALUT", false);
mt_test_pattern_tostring(num9, "\\S\\A\\L\\U\\T", "SALUT", false);
mt_test_pattern_tostring(num10, "S\\\\\\\\\\\\T", "S\\\\\\T", false);
mt_test_pattern_tostring(num11, "'Salut'\"Salut\"", "SalutSalut", false);
mt_test_pattern_tostring(num12, "\"\\\"\\\\\"", "\"\\", false);
mt_test_pattern_tostring(num13, "*\"*\"*", "***", false);
mt_test_pattern_tostring(num14, "?\"?\"?", "???", false);
mt_test_pattern_tostring(num15, "*'*'*", "***", false);
mt_test_pattern_tostring(num16, "?'?'?", "???", false);

void        suite_pattern_to_string(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
	SUITE_ADD_TEST(suite, test_num9);
	SUITE_ADD_TEST(suite, test_num10);
	SUITE_ADD_TEST(suite, test_num11);
	SUITE_ADD_TEST(suite, test_num12);
	SUITE_ADD_TEST(suite, test_num13);
	SUITE_ADD_TEST(suite, test_num14);
	SUITE_ADD_TEST(suite, test_num15);
	SUITE_ADD_TEST(suite, test_num16);
}
