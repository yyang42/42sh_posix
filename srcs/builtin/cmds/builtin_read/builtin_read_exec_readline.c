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
#include "utils.h"

static void			set_env_var(char *var, char *value)
{
	char			*tmp;

	tmp = utils_str_unescape_backslash(value);
	shenv_shvars_set(shenv_singleton(), var, tmp, "read");
	free(tmp);
}

static char			*strchr_ifs(char *ifs, char *str)
{
	char			*found;

	while (*str)
	{
		if (*str == '\\' && *(str + 1) != '\0')
		{
			str += 2;
		}
		else
		{
			found = twl_strchr(ifs, *str);
			if (found)
				return (str);
		}
		str++;
	}
	return (NULL);
}

static void			fill_vars(t_lst *vars, char *line, char *ifs)
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
		if (twl_strchr(ifs, *tmp))
			tmp++;
		tmp_end = strchr_ifs(ifs, tmp);
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
		set_env_var(var, value);
		if (!tmp_end)
			break ;
	}
	while ((var = twl_lst_pop_front(vars_copy)))
		set_env_var(var, "");
	twl_lst_del(vars_copy, NULL);
}

char				*builtin_read_gnl(void)
{
	int				ret;
	char			*line;

	ret = twl_get_next_line(0, &line);
	if (ret == -1)
	{
		LOGGER_ERROR("read: ret: %d", ret);
	}
	else if (ret > 0)
	{
		return (line);
	}
	return (NULL);
}

void				builtin_read_exec_readline(t_lst *remainders)
{
	char			*line;
	char			*accumulator;

	accumulator = twl_strdup("");
	while (true)
	{
		line = builtin_read_gnl();
		if (line)
		{
			accumulator = twl_strjoinfree(accumulator, line, 'l');
			free(line);
			if (utils_has_line_continuation(accumulator))
				continue ;
			break ;
		}
		else
		{
			break ;
		}
	}
	fill_vars(remainders, accumulator, shenv_get_ifs(shenv_singleton()));
	free(accumulator);
}
