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

#include "builtin/cmds/builtin_read.h"
#include "twl_gnl.h"
#include "utils.h"

static void			set_env_var(char *var,
		char *value, t_argparser_result *arg_res)
{
	char			*tmp;

	if (argparser_result_opt_is_set(arg_res, "r"))
	{
		shenv_shvars_set(shenv_singleton(), var, value, "read");
		return ;
	}
	tmp = utils_str_unescape_backslash(value);
	shenv_shvars_set(shenv_singleton(), var, tmp, "read");
	free(tmp);
}

static char			*strchr_mult(char *str,
		char *needles, t_argparser_result *arg_res)
{
	char			*found;

	if (argparser_result_opt_is_set(arg_res, "r"))
		found = twl_strchr_any(str, needles);
	else
		found = utils_strchr_multi_skip_escaped(str, needles);
	return (found);
	(void)arg_res;
}

void				builtin_read_exec_build_vars_from_line(
		t_argparser_result *arg_res, char *line, char *ifs)
{
	t_lst			*vars_copy;
	char			*var;
	char			*value;
	char			*tmp;
	char			*tmp_end;

	vars_copy = twl_lst_copy(arg_res->remainders, NULL);
	tmp = line;
	while ((var = twl_lst_pop_front(vars_copy)))
	{
		if (*tmp && twl_strchr(ifs, *tmp))
			tmp++;
		tmp_end = strchr_mult(tmp, ifs, arg_res);
		if (twl_lst_len(vars_copy) == 0)
			value = twl_strdup(tmp);
		else if (tmp_end)
		{
			value = twl_strnew(tmp_end - tmp);
			twl_strncpy(value, tmp, tmp_end - tmp);
		}
		else
			value = twl_strdup(tmp);
		tmp += twl_strlen(value);
		set_env_var(var, value, arg_res);
		free(value);
		if (!tmp_end)
			break ;
	}
	while ((var = twl_lst_pop_front(vars_copy)))
		set_env_var(var, "", arg_res);
	twl_lst_del(vars_copy, NULL);
}
