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

static void			print_job_fn(void *job_)
{
	t_job	*job;

	job = job_;
	twl_printf("<Object #%p>\n", job);
}

void				job_mgr_print(t_lst *jobs)
{
	twl_printf("%s>>>>>>>>>> job list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(jobs, print_job_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
