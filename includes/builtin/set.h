/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "basics.h"
# include "builtin.h"
# include "xopt.h"
# include "environment.h"

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
void				set_o_positive(t_environment *env);
void				set_o_negative(t_environment *env);
void				set_usage(char *flag);
void				set_check_args(t_set_opt *opt, t_environment *env);
void				test_set(char *str, t_environment *env);
#endif
