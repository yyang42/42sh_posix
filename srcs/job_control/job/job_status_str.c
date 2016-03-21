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
char				*job_status_str(t_job *job)
{
	char			*str_status;

	str_status = NULL;
	// twl_lprintf("job->pid %d\n", job->pid);
	// twl_lprintf("job->end_pid %d\n", job->end_pid);
	if (job->job_status == JOB_RUNNING)
		str_status = twl_strdup("Running");
	else if (job->job_status == JOB_DONE)
		twl_asprintf(&str_status, "Done(%d)", WEXITSTATUS(job->status));
	else if (job->job_status == JOB_TERMINATED)
		twl_asprintf(&str_status, "Terminated: %d", WTERMSIG(job->status));
	else if (job->job_status == JOB_STOPPED)
		twl_asprintf(&str_status, "Stopped(%d)", job->stopped_signal);
	else
		str_status = twl_strdup("Unknown");

	// if (job->end_pid == 0) {
	// 	if (job->stopped_signal)
	// 		twl_asprintf(&str_status, "Stopped(%d)", job->stopped_signal);
	// 	else
	// 		str_status = twl_strdup("Running");
	// }
	// else if (job->end_pid == job->pid)
	// {
	// 	if (WIFEXITED(job->status))
	// 		twl_asprintf(&str_status, "Done(%d)", WEXITSTATUS(job->status));
	// 	else if (WIFSIGNALED(job->status))
	// 		twl_asprintf(&str_status, "Terminated: %d", WTERMSIG(job->status));
	// 	else if (WIFSTOPPED(job->status))
	// 		twl_asprintf(&str_status, "Stopped(%d)", WSTOPSIG(job->status));
	// 	else if (WIFCONTINUED(job->status))
	// 		twl_asprintf(&str_status, "Continued(%d)", WSTOPSIG(job->status));
	// }
	// if (!str_status)
	// 	str_status = twl_strdup("Unknown");
	return (str_status);
}
