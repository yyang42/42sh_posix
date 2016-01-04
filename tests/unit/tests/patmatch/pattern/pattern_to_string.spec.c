#include <project.h>
#include "pattern.h"

#define PATTERN_TEST(a, b) \
{                                                       \
    t_pattern   *tmp;                                   \
    char        *actual;                                \
    tmp = pattern_new(a);                               \
    actual = pattern_to_string(tmp);                    \
    mt_assert(strcmp(actual, b) == 0);                  \
    pattern_del(tmp);                                   \
    free(actual);                                       \
}

static void test_bracket(t_test *test)
{
    PATTERN_TEST("[]", "[]");
    PATTERN_TEST("[\\[\\]]", "[[]]");
    PATTERN_TEST("[[:digit:]]", "[[:digit:]]");
    PATTERN_TEST("[a[:digit:]e[=a=]i[.ch.]o[:alnum:]u\\[\\]y]",
                "[a[:digit:]e[=a=]i[.ch.]o[:alnum:]u[]y]");
    PATTERN_TEST("[\"'\"]['\"']", "[\"'\"]['\"']");
    PATTERN_TEST("Makefil[[:helo]]test", "Makefil[[:helo]]test");
    PATTERN_TEST("*?k[AEIOU[:lower:]]**'f'\"i\"le", "*?k[AEIOU[:lower:]]**file");
}

static void test_simple(t_test *test)
{
    PATTERN_TEST("SALUT", "SALUT");
    PATTERN_TEST("\\S\\A\\L\\U\\T", "SALUT");
    PATTERN_TEST("S\\\\\\\\\\\\T", "S\\\\\\T");
    PATTERN_TEST("'Salut'\"Salut\"", "SalutSalut");
    PATTERN_TEST("\"\\\"\\\\\"", "\"\\");
    PATTERN_TEST("*\"*\"*", "***");
    PATTERN_TEST("?\"?\"?", "???");
    PATTERN_TEST("*'*'*", "***");
    PATTERN_TEST("?'?'?", "???");
}

void        suite_pattern_to_string(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_simple);
    SUITE_ADD_TEST(suite, test_bracket);
}
