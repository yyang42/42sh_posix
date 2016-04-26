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

#include "job_control/job_mgr.h"

static char			get_next_char(int len)
{
	char			sign_char;

	if (len == 0)
		sign_char = '+';
	else if (len == 1)
		sign_char = '-';
	else
		sign_char = ' ';
	return (sign_char);
}

static void			iter_fn(void *job_, int index, void *len_ptr)
{
	t_job	*job;
	int		len;

	job = job_;
	len = *(int *)len_ptr;
	job->sign = get_next_char(len - (index + 1));
}

void				job_mgr_update_sign(t_lst *jobs)
{
	int				len;

	len = twl_lst_len(jobs);
	twl_lst_iteri(jobs, iter_fn, &len);
}
