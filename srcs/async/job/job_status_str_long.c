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
#include "async/job.h"
#include "signal.h"

char				*job_status_str_long(t_job *this, bool incl_pid)
{
	char			*str;
	char			*pid_str;

	pid_str = twl_strdup("");
	if (incl_pid)
	{
		free(pid_str);
		twl_asprintf(&pid_str, "%d ", this->pid);
	}
	twl_asprintf(&str, "%s%-23s %s", pid_str, job_status_str(this), this->cmd_str);
	free(pid_str);
	return (str);
}
