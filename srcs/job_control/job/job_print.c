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

#include <sys/wait.h>
#include <errno.h>
#include "job_control/job.h"
#include "builtin/cmds/builtin_jobs.h"

void				job_print(t_job *this, int flags)
{
	char			*full_status;

	if (flags & BUILTIN_JOBS_FLAG_OPT_P)
	{
		twl_printf("%d\n", this->pid);
	}
	else
	{
		twl_printf("[%lld]%c ", this->job_id, this->sign);
		if (!flags & BUILTIN_JOBS_FLAG_OPT_L)
			twl_printf(" ");
		full_status = job_status_str_long(this, flags & BUILTIN_JOBS_FLAG_OPT_L);
		twl_printf("%s\n", full_status);
		free(full_status);
	}
}
