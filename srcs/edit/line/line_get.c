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

#include "edit/line.h"
#include "twl_ctype.h"

static void		log_it(int output, char *buffer, char *to_print)
{
	int			ind_buf;
	int			index;

	index = twl_sprintf(to_print, "twl_strlen(%03zu): %03i: ", twl_strlen(buffer), output);
	ind_buf = 0;
	while (buffer[ind_buf])
	{
		if (buffer[ind_buf] == '\n')
			index += twl_sprintf(to_print + index, "\\n");
		else if (buffer[ind_buf] == '\t')
			index += twl_sprintf(to_print + index, "\\t");
		else if (buffer[ind_buf] == ' ')
			index += twl_sprintf(to_print + index, "' '");
		else if (twl_isprint(buffer[ind_buf]))
			index += twl_sprintf(to_print + index, "%c", buffer[ind_buf]);
		else
			index += twl_sprintf(to_print + index, "\\x%02hhx", buffer[ind_buf]);
		ind_buf += 1;
	}
}

char			*line_get(t_line *this)
{
	char		buffer[16];
	char		to_print[255];
	int			output;

	twl_memset(buffer, 0, sizeof(buffer));
	while ((output = read(0, buffer, sizeof(buffer) - 1)) != -1)
	{
		twl_memset(to_print, 0, sizeof(to_print));
		log_it(output, buffer, to_print);
		LOG_DEBUG("%s", to_print);
		if (*buffer == 0x04 || !output)
			return ("exit");
		twl_memset(buffer, 0, sizeof(buffer));
	}
	twl_memset(to_print, 0, sizeof(to_print));
	log_it(output, buffer, to_print);
	LOG_DEBUG("%s %s", to_print, strerror(errno));
	return (NULL);
	(void)this;
}
