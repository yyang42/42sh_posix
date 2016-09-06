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

char				*builtin_read_gnl(char **remainder_ptr)
{
	int				ret;
	char			*line;

	ret = twl_gnl(0, &line, remainder_ptr);
	if (ret == -1)
	{
		LOG_ERROR("read: ret: %d", ret);
		shenv_singleton()->last_exit_code = 2;
	}
	else if (ret == 0)
	{
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
	else if (ret > 0)
	{
		return (line);
	}
	return (NULL);
}

void				builtin_read_exec_readline(t_argparser_result *arg_res)
{
	char			*line;
	char			*accumulator;

	accumulator = twl_strdup("");
	if (isatty(0))
	{
		utils_tcsetpgrp_for_tty(getpid(), 0);
	}
	while (true)
	{
		line = builtin_read_gnl(shenv_singleton()->shenv_read_remainder_ptr);
		if (line)
		{
			accumulator = twl_strjoinfree(accumulator, line, 'l');
			free(line);
			if (!argparser_result_opt_is_set(arg_res, "r")
				&& utils_str_has_line_continuation(accumulator))
				continue ;
		}
		break ;
	}
	builtin_read_exec_build_vars_from_line(
		arg_res, accumulator, shenv_get_ifs(shenv_singleton()));
	free(accumulator);
}
