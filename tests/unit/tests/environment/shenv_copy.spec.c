#include <project.h>

#include "shenv/shenv.h"

static void	test_copy_shvars(t_test *test)
{
	t_shenv		*src;
	t_shenv		*clone;

	src = shenv_new();
	shenv_shvars_set(src, "mykey", "myvar", NULL);
	clone = shenv_copy(src);

	mt_assert(strcmp(shenv_shvars_get(src, "mykey")->shvar_value, shenv_shvars_get(clone, "mykey")->shvar_value) == 0);
	mt_assert(src->shenv_shvars != clone->shenv_shvars);
	mt_assert(shenv_shvars_get(src, "mykey")->shvar_value != shenv_shvars_get(clone, "mykey")->shvar_value);

	shenv_del(src);
	shenv_del(clone);
}

void	suite_shenv_copy(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_copy_shvars);
}
