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

#ifndef BUILTIN_SET_H
# define BUILTIN_SET_H

# include "basics.h"
# include "builtin/builtin.h"
# include "twl_opt.h"
# include "twl_opt_elem.h"

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

void				builtin_set_exec(t_lst *tokens, t_shenv *env);
t_set_opt			*builtin_set_opt_new(char **argv, char *valid_opts);
void				builtin_set_opt_del(t_set_opt *xopt);
char				**builtin_set_opt_new_parse_arg_opt_and_return_non_opt_args__(
	char **arr_opts, t_set_opt *opt, char *valid_opts);
char				*builtin_set_opt_check_invalid_opts(t_set_opt *opt);
int					builtin_set_opt_exist(t_set_opt *twl_opt, char *opt_key);
void				builtin_set_o_positive(t_shenv *env);
void				builtin_set_o_negative(t_shenv *env);
void				builtin_set_check_args(t_set_opt *opt, t_shenv *env);
int					builtin_set_check_invalid_opts(t_set_opt *opt, char *exe_name,
																char *flags);
void				builtin_set_exec_print(t_shenv *this);

#endif
