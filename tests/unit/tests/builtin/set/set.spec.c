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
    env = environment_singleton();
    set("set -x -a -b");
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "xab") == 0);
}

static void test_unset_flag(t_test *test)
{
    t_environment        *env;
    char                *flags;

    (void)test;
    env = environment_singleton();
    set("set -x -a -b");
    set("set +x");
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "ab") == 0);
    set("set +b");
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "a") == 0);
    set("set +a");
    flags = environment_concat_flags(env);
    mt_assert(twl_strcmp(flags, "") == 0);
}

// static void     test_o_positive(t_test *test)
// {
//     t_environment        *env;
//
//     (void)test;
//     env = environment_singleton();
//     set("set -a");
//     set("set -e");
//     set("set -f");
//     set("set +o");
// }
//
// static void     test_o_negative(t_test *test)
// {
//     t_environment        *env;
//
//     (void)test;
//     env = environment_singleton();
//     set("set -a");
//     set("set -e");
//     set("set -f");
//     set("set -o");
// }

void            suite_set(t_suite *suite)
{
    (void)suite;
    SUITE_ADD_TEST(suite, test_set_flag);
    SUITE_ADD_TEST(suite, test_unset_flag);
    // SUITE_ADD_TEST(suite, test_o_positive);
    // SUITE_ADD_TEST(suite, test_o_negative);
}
