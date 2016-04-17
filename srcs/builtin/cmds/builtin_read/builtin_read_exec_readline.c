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
#include "twl_get_next_line.h"

static void			fill_vars(t_lst *vars, char *line)
{
	t_lst			*vars_copy;
	char			*var;
	char			*value;
	char			*tmp;
	char			*tmp_end;

	vars_copy = twl_lst_copy(vars, NULL);
	tmp = line;
	while ((var = twl_lst_pop_front(vars_copy)))
	{
		while (twl_strchr(shenv_get_ifs(shenv_singleton()), *tmp))
			tmp++;
		tmp_end = twl_strchr_any(tmp, shenv_get_ifs(shenv_singleton()));
		if (twl_lst_len(vars_copy) == 0)
		{
			value = twl_strdup(tmp);
		}
		else if (tmp_end)
		{
			value = twl_strnew(tmp_end - tmp);
			twl_strncpy(value, tmp, tmp_end - tmp);
		}
		else
		{
			value = twl_strdup(tmp);
		}
		LOGGER_DEBUG("read: var    : %s", var);
		LOGGER_DEBUG("read: value  : %s", value);
		LOGGER_DEBUG("read: tmp    : %s", tmp);
		LOGGER_DEBUG("read: tmp_end: %s", tmp_end);
		tmp += twl_strlen(value);
		shenv_shvars_set(shenv_singleton(), var, value, "read");
		if (!tmp_end)
			break ;
	}
	while ((var = twl_lst_pop_front(vars_copy)))
		shenv_shvars_set(shenv_singleton(), var, "", "read");
	twl_lst_del(vars_copy, NULL);
}

void				builtin_read_exec_readline(t_lst *remainders)
{
	int				ret;
	char			*line;

	ret = twl_get_next_line(0, &line);
	LOGGER_DEBUG("read: ret: %d", ret);
	LOGGER_DEBUG("read: line: {%s}", line);
	if (ret == -1)
	{
		LOGGER_ERROR("read: ret: %d", ret);
	}
	else if (ret > 0)
	{
		fill_vars(remainders, line);
		free(line);
	}
}
