#include <project.h>
#include "pattern_matching/substr.h"

#define mt_test_substr(test_name, string, pattern, expected, debug)		\
static void test_## test_name(t_test *test)								\
{																		\
	t_substr	*tmp = substr_new();									\
	char		*actual = substr_percentpercent(tmp, string, pattern);	\
	if (debug)															\
	{																	\
		printf("=== case: %s - %s\n", string, pattern);					\
		printf("actual    {%s}\n", actual);								\
		printf("expected  {%s}\n", expected);							\
	}																	\
	mt_assert(strcmp(actual, expected) == 0);							\
	free(actual);														\
	substr_del(tmp);													\
}

mt_test_substr(num1, "abc", "c", "ab", false);
mt_test_substr(num2, "abc", "abc", "", false);
mt_test_substr(num3, "abc", "", "abc", false);
mt_test_substr(num4, "olalol", "o*", "", false);
mt_test_substr(num5, "Sapete.c", "[[:punct:]][[:lower:]]", "Sapete", false);
mt_test_substr(num6, "substr.csshtmljstasoeur", ".*?*?*[aze]*", "substr", false);
mt_test_substr(num7, "J'aime les endives", "*", "", false);
mt_test_substr(num8, "Lorem Ipsum", "m*", "Lore", false);
//mt_test_substr(num9, "", "", "", true);
//mt_test_substr(num10, "", "", "", true);
//mt_test_substr(num11, "", "", "", true);
//mt_test_substr(num12, "", "", "", true);
//mt_test_substr(num13, "", "", "", true);
//mt_test_substr(num14, "", "", "", true);
//mt_test_substr(num15, "", "", "", true);

void		suite_substr_percentpercent(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_num1);
	SUITE_ADD_TEST(suite, test_num2);
	SUITE_ADD_TEST(suite, test_num3);
	SUITE_ADD_TEST(suite, test_num4);
	SUITE_ADD_TEST(suite, test_num5);
	SUITE_ADD_TEST(suite, test_num6);
	SUITE_ADD_TEST(suite, test_num7);
	SUITE_ADD_TEST(suite, test_num8);
//	SUITE_ADD_TEST(suite, test_num9);
//	SUITE_ADD_TEST(suite, test_num10);
//	SUITE_ADD_TEST(suite, test_num11);
//	SUITE_ADD_TEST(suite, test_num12);
//	SUITE_ADD_TEST(suite, test_num13);
//	SUITE_ADD_TEST(suite, test_num14);
//	SUITE_ADD_TEST(suite, test_num15);
}

