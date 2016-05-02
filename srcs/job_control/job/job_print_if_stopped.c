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

#include "job_control/job.h"
#include "shenv/shenv.h"

void				job_print_if_stopped(t_job *job)
{
	if (shenv_singleton()->is_interactive_shell)
		return ;
	job_exec_update_status(job);
	if (job->job_status == JOB_STOPPED)
	{
		job->sign = '+';
	    twl_putchar('\n');
	    job_print(job, 0);
	}
}
