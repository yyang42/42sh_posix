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
#include "builtin/set.h"

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

t_lst				*get_list(t_set_opt *opt, char c)
{
	return (c == '+' ? opt->positive_opts : opt->negative_opts);
}

char				**set_opt_new_parse_arg_opt_and_return_non_opt_args__(
							char **opts, t_set_opt *opt, char *valid_opts)
{
	char			*opt_wo_hyphen;
	char			*n_arg;
	int				i;

	i = 0;
	while (opts[i] && (*opts[i] == '-' || *opts[i] == '+'))
	{
		opt_wo_hyphen = opts[i] + 1;
		if (twl_strequ(opts[i], "--"))
		{
			i++;
			break ;
		}
		if (is_valid_opt_with_param(opt_wo_hyphen, valid_opts))
		{
			n_arg = opts[i + 1];
			parse_opt_with_param(opt_wo_hyphen, n_arg, get_list(opt, *opts[i]));
			if (opts[i + 1] != NULL)
				i++;
		}
		else
			parse_single_arg(opt_wo_hyphen, get_list(opt, *opts[i]));
		i++;
	}
	return (&opts[i]);
}
