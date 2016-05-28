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

char				*job_status_str_long(t_job *this, bool incl_pid)
{
	char			*str;
	char			*pid_str;
	char			*job_status;

	pid_str = twl_strdup("");
	if (incl_pid)
	{
		free(pid_str);
		twl_asprintf(&pid_str, "%d ", this->pid);
	}
	job_status = job_status_str(this);
	twl_asprintf(&str, "%s%-23s %s", pid_str, job_status, this->cmd_str);
	free(pid_str);
	free(job_status);
	return (str);
}
