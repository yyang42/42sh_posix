#include <project.h>

#include "builtin/builtin_env.h"
#include "environment.h"
#include <stdlib.h>
#include <string.h>
#include "twl_stdio.h"
#include "builtin/builtin_read.h"
#include "token/tokenizer.h"
#include <unistd.h>

#define mt_test_read(num, input)	\
static void test_## num(t_test *test) \
{ \
	t_lst	*l = twl_lst_new(); \
	int p[2]; \
 \
	dup2(p[1], 1); \
	pipe(p); \
	write(p[1], input, strlen(input)); \
	dup2(p[0], 0); \
	builtin_read_exec(l, NULL); \
	close(p[0]); \
	close(p[1]); \
	twl_lst_del(l, free); \
	mt_assert(true); \
}

mt_test_read(lol, "Bonjouaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaar")

void	suite_builtin_read(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_lol);
}
