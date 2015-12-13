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

#include <stdlib.h>
#include "twl_opt.h"
#include "twl_arr.h"
#include "twl_xstring.h"
#include "twl_string.h"
#include "twl_opt_elem.h"
#include "set.h"

static void			push_non_opt_to_lst(void *non_opt_arg,
														void *non_opt_arg_lst_)
{
	t_lst			*non_opt_arg_lst;

	non_opt_arg_lst = non_opt_arg_lst_;
	twl_lst_push(non_opt_arg_lst, twl_strdup(non_opt_arg));
}

static void			parse_argv(char **arr_opts, t_set_opt *opt,
														char *valid_opts)
{
	char			**non_opt_args;

	non_opt_args = set_opt_new_parse_arg_opt_and_return_non_opt_args__(
													arr_opts, opt, valid_opts);
	opt->args = twl_lst_new();
	if (non_opt_args)
		twl_arr_iter(non_opt_args, push_non_opt_to_lst, opt->args);
}

t_set_opt			*set_opt_new(char **argv, char *valid_opts)
{
	t_set_opt		*opt;
	char			**argv_without_cmd;

	opt = malloc(sizeof(t_set_opt));
	opt->cmd = twl_strdup(argv[0]);
	argv_without_cmd = argv + 1;
	opt->negative_opts = twl_lst_new();
	opt->positive_opts = twl_lst_new();
	opt->valid_opts = twl_strdup(valid_opts);
	parse_argv(argv_without_cmd, opt, valid_opts);
	return (opt);
}
