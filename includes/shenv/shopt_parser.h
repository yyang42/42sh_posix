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

#ifndef SHOPT_PARSER_H
# define SHOPT_PARSER_H

# include "basics.h"
# include "shenv/shenv.h"

# define SET_OPT_VALID_OPTS "-abCefhmnouvx"
# define POSITIVE_OPT 1
# define NEGATIVE_OPT -1

typedef struct		s_set_opt
{
	t_lst			*positive_opts;
	t_lst			*negative_opts;
	t_lst			*args;
	char			*valid_opts;
}					t_set_opt;

t_set_opt			*shopt_parser_new(char **argv, char *valid_opts);
void				shopt_parser_del(t_set_opt *xopt);
char				**shopt_parser_new_parse_arg_opt_and_return_non_opt_args__(
					char **arr_opts, t_set_opt *opt, char *valid_opts);
char				*shopt_parser_check_invalid_opts(t_set_opt *opt);
int					shopt_parser_exist(t_set_opt *twl_opt, char *opt_key);
void				shopt_parser_check_args(t_set_opt *opt, t_shenv *env);

#endif
