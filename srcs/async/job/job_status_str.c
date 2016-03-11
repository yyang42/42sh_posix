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
#include "async/job.h"
#include "signal.h"
#include <sys/wait.h>
 #include <stdio.h>
 #include <errno.h>
/*
static char			*handle_signaled(int stat_val)
{
	char			*str_status;

	if (WTERMSIG(stat_val) == 5)
	{
		str_status = twl_strdup("Running");
	}
	else
	{
		twl_asprintf(&str_status, "WTERMSIG(%d)", WTERMSIG(stat_val));
	}
	return (str_status);
}

static char			*handle_stopped(int stat_val)
{
	char			*str_status;

	twl_asprintf(&str_status, "Stopped(%s)", WSTOPSIG(stat_val));
	return (str_status);
}
*/
char				*job_status_str(t_job *this)
{
	char			*str_status;
	int				status;
    pid_t child_pid, end_pid;

	child_pid = this->pid;
	// waitpid(this->pid, &stat_val, WNOHANG | WCONTINUED | WUNTRACED);
	end_pid = waitpid(child_pid, &status, WNOHANG|WUNTRACED);
	str_status = NULL;
	if (end_pid == -1) {            /* error calling waitpid       */
        perror("waitpid error");
		exit(EXIT_FAILURE);
	}
	else if (end_pid == 0) {        /* child still running         */
		str_status = twl_strdup("Running");
	}
	else if (end_pid == child_pid) {  /* child ended                 */
		if (WIFEXITED(status))
			twl_asprintf(&str_status, "Done(%d)", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			str_status = twl_strdup("Child ended because of an uncaught signal");
		else if (WIFSTOPPED(status))
			str_status = twl_strdup("Child process has stopped");
		else if (WEXITSTATUS(status) == 0)
			twl_asprintf(&str_status, "WEXITSTATUS(stat_val) %d", (WEXITSTATUS(status)));
	}
	if (!str_status)
		str_status = twl_strdup("Unknown");
	return (str_status);
}
