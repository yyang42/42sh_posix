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

#include "builtin/cmds/builtin_times.h"
#include "twl_stdlib.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>

static void			timeval_to_secs(struct timeval *tvp, time_t *sp, int *sfp)
{
	int rest;

	*sp = tvp->tv_sec;
	*sfp = tvp->tv_usec % 1000000;
	rest = *sfp % 1000;
	*sfp = (*sfp * 1000) / 1000000;
	if (rest >= 500)
		*sfp += 1;
	if (*sfp >= 1000)
	{
		*sp += 1;
		*sfp -= 1000;
	}
}

static void			print_timeval(struct timeval *tvp)
{
	time_t	timestamp;
	long	minutes;
	int		seconds;
	int		seconds_fraction;

	timeval_to_secs(tvp, &timestamp, &seconds_fraction);
	minutes = timestamp / 60;
	seconds = timestamp % 60;
	twl_printf("%ldm%d.%03ds", minutes, seconds, seconds_fraction);
}

int					builtin_times_exec(t_lst *tokens, t_shenv *env)
{
	struct rusage self;
	struct rusage kids;

	(void)tokens;
	(void)env;
	getrusage(RUSAGE_SELF, &self);
	getrusage(RUSAGE_CHILDREN, &kids);
	print_timeval(&self.ru_utime);
	twl_putchar(' ');
	print_timeval(&self.ru_stime);
	twl_putchar('\n');
	print_timeval(&kids.ru_utime);
	twl_putchar(' ');
	print_timeval(&kids.ru_stime);
	twl_putchar('\n');
	return (0);
}
