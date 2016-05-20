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

#include "prog.h"
#include "twl_gnl.h"
#include "ast/ast.h"
#include "shenv/shenv.h"

static int          count_single_quote(char *str)
{
	int             count;

	count = 0;
	while (*str)
	{
		if (*str == '\\' && *(str + 1))
		{
			str += 2;
			continue ;
		}
		if (*str == '\'')
		{
			count++;
		}
		str++;
	}
	return (count);
}

static char         *read_gnl(int fd, char **gnl_remainder_ptr, int *line_ptr)
{
	char            *line;
	char            *accumulator;
	int				gnl_ret;
	int				has_open;

	accumulator = twl_strdup("");
	while ((gnl_ret = twl_gnl(fd, &line, gnl_remainder_ptr)) > 0)
	{
		*line_ptr += 1;
		accumulator = twl_strjoinfree(accumulator, line, 'l');
		if (count_single_quote(accumulator) % 2)
		{
			accumulator = twl_strjoinfree(accumulator, "\n", 'l');
			continue ;
		}
		if (utils_str_has_line_continuation(accumulator))
		{
			accumulator[twl_strlen(accumulator) - 1] = '\0';
			continue ;
		}
		accumulator = twl_strjoinfree(accumulator, "\n", 'l');
		free(line);
		has_open = ast_utils_check_has_open(accumulator);
		if (!has_open)
			break ;
	}
	if (gnl_ret == GNL_ERR_BINARY_FILE)
	{
		shenv_singl_error(126, "cannot execute binary file");
		free(accumulator);
		return (NULL);
	}
	if (twl_strlen(accumulator) == 0)
	{
		free(accumulator);
		return (NULL);
	}
	return (accumulator);
}

void                prog_utils_run_fd(int fd)
{
	char            *input;
	char            *gnl_remainder;
	int             line;
	int             line_prev;

	gnl_remainder = NULL;
	line = 0;
	line_prev = 0;
	while ((input = read_gnl(fd, &gnl_remainder, &line)))
	{
		prog_utils_run_input(input, line_prev + 1);
		if (shenv_singleton()->shenv_has_syntax_error)
			break ;
		line_prev = line;
	}
	free(input);
	free(gnl_remainder);
}
