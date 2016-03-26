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

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "twl_printf.h"
#include "twl_stdio.h"

void				logger_printf(const char *fn, int line, const char *fmt, ...)
{
	t_pf			*pf;
	int				fd;
    time_t			timer;
    char			buffer[26];
    struct tm		*tm_info;

    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
	fd = open(".debug.out", O_CREAT | O_WRONLY | O_APPEND, 0644);
	pf = pf_create((char *)fmt);
	twl_dprintf(fd, "%s [%s:%d] ", buffer, fn, line);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	pf_print_fd(pf, fd);
	twl_dprintf(fd, "\n");
	va_end(pf->arglist);
	pf_free(pf);
	close(fd);
}

