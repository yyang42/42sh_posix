# include "basics.h"
# include "xopt.h"
# define SET_OPT_VALID_OPTS "-abCefhmnouvx"
# define POSITIVE_OPT 1
# define NEGATIVE_OPT -1
typedef struct		s_set_opt
{
	t_lst			*positive_opts;
	t_lst			*negative_opts;
	t_lst			*args;
	char			*valid_opts;
	char			*cmd;
}					t_set_opt;

void				set(char *str);
t_set_opt			*set_opt_new(char **argv, char *valid_opts);
void				set_opt_del(t_set_opt *xopt);
char				**set_opt_new_parse_arg_opt_and_return_non_opt_args__(
								char **arr_opts, t_set_opt *opt, char *valid_opts);
char				*set_opt_check_invalid_opts(t_set_opt *opt);
int					set_opt_exist(t_set_opt *twl_opt, char *opt_key);
void				set_add_flag(char *flag);
void				set_remove_flag(char *flag);
void				set_o_positive();
void				set_o_negative();
void				set_usage(char *flag);
void				set_check_args(t_set_opt *opt);
