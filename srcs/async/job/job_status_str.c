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
/*
	Running
		Indicates that the job has not been suspended by a signal and has not exited.
	Done
		Indicates that the job completed and returned exit status zero.
	Done(code)
		Indicates that the job completed normally and that it exited with the specified non-zero exit status, code, expressed as a decimal number.
	Stopped
		Indicates that the job was suspended by the SIGTSTP signal.
	Stopped (SIGTSTP)
		Indicates that the job was suspended by the SIGTSTP signal.
	Stopped (SIGSTOP)
		Indicates that the job was suspended by the SIGSTOP signal.
	Stopped (SIGTTIN)
		Indicates that the job was suspended by the SIGTTIN signal.
	Stopped (SIGTTOU)
		Indicates that the job was suspended by the SIGTTOU signal.

*/
char				*job_status_str(t_job *this)
{
	char			*str_status;

	job_waitpid_update(this);
	str_status = NULL;
	if (this->end_pid == 0) {
		str_status = twl_strdup("Running");
	}
	else if (this->end_pid == this->pid)
	{
		if (WIFEXITED(this->status))
			twl_asprintf(&str_status, "Done(%d)", WEXITSTATUS(this->status));
		else if (WIFSIGNALED(this->status))
			twl_asprintf(&str_status, "Terminated: %d", WTERMSIG(this->status));
		else if (WIFSTOPPED(this->status))
			twl_asprintf(&str_status, "Stopped(%d)", WSTOPSIG(this->status));
	}
	if (!str_status)
		str_status = twl_strdup("Unknown");
	return (str_status);
}
