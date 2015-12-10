#include <project.h>

#include "environment.h"
#include "set.h"
#include "xopt.h"
#include <stdlib.h>

static void     test_set_flag(t_test *test)
{
    t_environment        *env;
    char                *flags;

    (void)test;
    env = environment_new();
	environment_init(env);
    test_set("set -x -a -b", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "xab") == 0);
	environment_del(env);
}

static void test_unset_flag(t_test *test)
{
    t_environment        *env;
    char                *flags;

    (void)test;
	env = environment_new();
	environment_init(env);
    test_set("set -x -a -b", env);
    test_set("set +x", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "ab") == 0);
    test_set("set +b", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "a") == 0);
    test_set("set +a", env);
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "") == 0);
	environment_del(env);
}

static void test_wrong_flag(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	test_set("set -a -b", env);
	test_set("set -C -z -e", env);
	mt_assert(twl_lst_len(env->flags) == 2);
	environment_del(env);
}

static void 	test_set_verbose(t_test *test)
{
	t_environment		*env;
	char				*flags;

	(void)test;
	env = environment_new();
	environment_init(env);
	test_set("set -o errexit", env);
	test_set("set -o nounset", env);
	test_set("set -o noexec lol", env);
	flags = environment_concat_flags(env);
	mt_assert(twl_strcmp(flags, "eun") == 0);
	environment_del(env);
}

static void 	test_unset_verbose(t_test *test)
{
	t_environment		*env;
	char				*flags;

	(void)test;
	env = environment_new();
	environment_init(env);
	test_set("set -o errexit", env);
	test_set("set -o nounset", env);
	test_set("set -o noexec lol", env);
	test_set("set +o nounset", env);
	flags = environment_concat_flags(env);
	mt_assert(twl_strcmp(flags, "en") == 0);
	environment_del(env);
}

static void 	test_set_pos_param(t_test *test)
{
	t_environment		*env;

	(void)test;
	env = environment_new();
	environment_init(env);
	test_set("set pouet lol", env);
	mt_assert(twl_lst_len(env->pos_params) == 2);
	test_set("set hihi haha", env);
	mt_assert(twl_lst_len(env->pos_params) == 2);
	environment_del(env);
}


void            suite_set(t_suite *suite)
{
	(void)suite;
	SUITE_ADD_TEST(suite, test_set_flag);
	SUITE_ADD_TEST(suite, test_unset_flag);
	SUITE_ADD_TEST(suite, test_wrong_flag);
	SUITE_ADD_TEST(suite, test_set_verbose);
	SUITE_ADD_TEST(suite, test_unset_verbose);
	SUITE_ADD_TEST(suite, test_set_pos_param);
}
