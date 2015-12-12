#include <project.h>

#include "utils.h"

static void simple_without_quote(t_test *test)
{
	t_lst			*segs;

	segs = str_split_except_quote("aaa 123 bbb");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "123") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 2), "bbb") == 0);
}

static void simple_str_with_double_quote(t_test *test)
{
	t_lst			*segs;

	segs = str_split_except_quote("aaa \"1 2\" bbb");
	// twl_lst_putstr(segs, "\n");
	// printf("\n");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "\"1 2\"") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 2), "bbb") == 0);
}

static void simple_str_with_escaped_quote(t_test *test)
{
	t_lst			*segs;

	segs = str_split_except_quote("aaa 1\\\"2 bbb");
	// twl_lst_putstr(segs, "\n");
	// printf("\n");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "1\\\"2") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 2), "bbb") == 0);
}

static void simple_str_with_escaped_quote_inside_quote(t_test *test)
{
	t_lst			*segs;

	segs = str_split_except_quote("aaa \"1\\\" 2\" bbb");
	// twl_lst_putstr(segs, "\n");
	// printf("\n");
	mt_assert(strcmp(twl_lst_get(segs, 0), "aaa") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 1), "\"1\\\" 2\"") == 0);
	mt_assert(strcmp(twl_lst_get(segs, 2), "bbb") == 0);
}

static void empty_string(t_test *test)
{
	t_lst			*segs;

	segs = str_split_except_quote("");
	// twl_lst_putstr(segs, "\n");
	// printf("\n");
	mt_assert(twl_lst_len(segs) == 0);
}

static void only_space_string(t_test *test)
{
	t_lst			*segs;

	segs = str_split_except_quote("  ");
	mt_assert(twl_lst_len(segs) == 0);
}

static void quote_at_the_begining(t_test *test)
{
	t_lst			*segs;
	char			*str = "\\\"123\"";

	str = str + 1;
	segs = str_split_except_quote(str);
	mt_assert(twl_lst_len(segs) == 1);
	mt_assert(strcmp(twl_lst_get(segs, 0), "\"123\"") == 0);
}

static void slash_alone(t_test *test)
{
	t_lst			*segs;
	char			*str = "\\";

	segs = str_split_except_quote(str);
	// twl_lst_putstr(segs, "\n");
	// printf("\n");
	// printf("len %zu\n", twl_lst_len(segs));
	mt_assert(twl_lst_len(segs) == 1);
	mt_assert(strcmp(twl_lst_get(segs, 0), "\\") == 0);
}

static void normal_tokens_with_quote_tokens(t_test *test)
{
	t_lst			*segs;
	char			*str = "aa\"bb cc\"dd";

	segs = str_split_except_quote(str);
	printf("======\n");
	twl_lst_putstr(segs, "\n");
	printf("\n");
	printf("len %zu\n", twl_lst_len(segs));
	mt_assert(twl_lst_len(segs) == 1);
	mt_assert(strcmp(twl_lst_get(segs, 0), "aa\"bb cc\"dd") == 0);
}


static void double_slash_alone(t_test *test)
{
	t_lst			*segs;
	char			*str = "\\\\\"a b\\\\\"";

	segs = str_split_except_quote(str);
	printf("======\n");
	twl_lst_putstr(segs, "\n");
	printf("\n");
	printf("len %zu\n", twl_lst_len(segs));
	mt_assert(twl_lst_len(segs) == 1);
	mt_assert(strcmp(twl_lst_get(segs, 0), "\\\\\"a b\\\\\"") == 0);
}

void	suite_str_split_except_quote(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_without_quote);
	SUITE_ADD_TEST(suite, simple_str_with_double_quote);
	SUITE_ADD_TEST(suite, simple_str_with_escaped_quote);
	SUITE_ADD_TEST(suite, simple_str_with_escaped_quote_inside_quote);
	SUITE_ADD_TEST(suite, empty_string);
	SUITE_ADD_TEST(suite, only_space_string);
	SUITE_ADD_TEST(suite, quote_at_the_begining);
	SUITE_ADD_TEST(suite, slash_alone);
	SUITE_ADD_TEST(suite, normal_tokens_with_quote_tokens);
	SUITE_ADD_TEST(suite, double_slash_alone);
}
