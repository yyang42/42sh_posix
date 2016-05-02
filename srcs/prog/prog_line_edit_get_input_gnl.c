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
#include <stdlib.h>

#define BUFF_SIZE 10000

char				*prog_line_edit_get_input_gnl(t_prog *prog)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				errno_save;

	ret = read(0, buff, BUFF_SIZE);
	errno_save = errno;
	twl_printf("ret %d\n", ret);
	if (ret < 0)
	{
		twl_dprintf(2, "[error] %s\n", strerror(errno_save));
		exit(1);
	}
	else if (ret == 0)
	{
		twl_dprintf(2, "ret zero");
	}
	else
	{
		buff[ret] = 0;
		twl_printf("read: {%s}\n", buff);
	}
	return (twl_strdup(buff));
	(void)prog;
}
