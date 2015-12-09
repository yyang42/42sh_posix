# include "basics.h"
# include "xopt.h"
# define SET_OPT_VALID_OPTS "-abCefhmnouvx"

typedef struct		s_builtin_set_opts
{
	t_lst	*opts;
	t_lst	*args;
}					t_builtin_set_opts;

void				builtin_set(char *str);
