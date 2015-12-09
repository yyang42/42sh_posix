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

#include "twl_stdlib.h"
#include "twl_opt.h"
#include "twl_arr.h"
#include "twl_xstring.h"
#include "twl_string.h"
#include "twl_opt_elem.h"
#include "set.h"

static void			parse_single_arg(char *arg, t_lst *opts)
{
	char			opt_key[2];

	twl_bzero(opt_key, 2);
	while (*arg)
	{
		*opt_key = *arg;
		twl_lst_push(opts, twl_opt_elem_new(opt_key, NULL));
		arg++;
	}
}

static void			parse_opt_with_param(char *key, char *value, t_lst *opts)
{
	char			opt_key[2];

	twl_bzero(opt_key, 2);
	*opt_key = *key;
	twl_lst_push(opts, twl_opt_elem_new(opt_key, value));
}

static bool			is_valid_opt_with_param(char *opt_without_hyphen,
															char *valid_opts)
{
	char *found_opt;

	found_opt = twl_strchr(valid_opts, opt_without_hyphen[0]);
	if (found_opt && (found_opt[1] == ':'))
		return (true);
	return (false);
}

char				**set_opt_new_parse_arg_opt_and_return_non_opt_args__(
							char **arr_opts, t_set_opt *opt, char *valid_opts)
{
	char			*opt_without_hyphen;
	char			*next_arg;
	int				i;

	i = 0;
	while (arr_opts[i] && (*arr_opts[i] == '-' || *arr_opts[i] == '+'))
	{
		opt_without_hyphen = arr_opts[i] + 1;
		if (twl_strequ(arr_opts[i], "--"))
		{
			i++;
			break ;
		}
		if (is_valid_opt_with_param(opt_without_hyphen, valid_opts))
		{
			next_arg = arr_opts[i + 1];
			if (*arr_opts[i] == '+')
				parse_opt_with_param(opt_without_hyphen, next_arg,
					opt->positive_opts);
			else if(*arr_opts[i] == '-')
				parse_opt_with_param(opt_without_hyphen, next_arg,
					opt->negative_opts);
			if (arr_opts[i + 1] != NULL)
				i++;
		}
		else
		{
			if (*arr_opts[i] == '+')
				parse_single_arg(opt_without_hyphen, opt->positive_opts);
			else if (*arr_opts[i] == '-')
				parse_single_arg(opt_without_hyphen, opt->negative_opts);
		}
		i++;
	}
	return (&arr_opts[i]);
}
