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

char				*job_status_str(t_job *this)
{
	char			*str_status;
	// pid_t			pid;
	int				status;
    pid_t childID, endID;

	childID = this->pid;
	// waitpid(this->pid, &stat_val, WNOHANG | WCONTINUED | WUNTRACED);
	twl_printf("childID %d\n", childID);
	endID = waitpid(childID, &status, WNOHANG|WUNTRACED);
	if (endID == -1) {            /* error calling waitpid       */
        perror("waitpid error");
		// twl_dprintf(2, "waitpid error");
		exit(EXIT_FAILURE);
	}
	else if (endID == 0) {        /* child still running         */
		// time(&when);
		str_status = twl_strdup("Parent waiting");
		sleep(1);
	}
	else if (endID == childID) {  /* child ended                 */
		if (WIFEXITED(status))
			str_status = twl_strdup("Child ended normally.n");
		else if (WIFSIGNALED(status))
			str_status = twl_strdup("Child ended because of an uncaught signal.n");
		else if (WIFSTOPPED(status))
			str_status = twl_strdup("Child process has stopped.n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		str_status = twl_strdup("unknown");
	}
	(void)handle_signaled;
	(void)handle_stopped;
	// stat_val = job_waitpid(this);
	// if (WIFEXITED(stat_val))
	// {
	// 	if (WEXITSTATUS(stat_val) == 0)
	// 		twl_asprintf(&str_status, "Done");
	// 	else
	// 		twl_asprintf(&str_status, "Done(%d)", WEXITSTATUS(stat_val));
	// }
	// else if (WIFSTOPPED(stat_val))
	// 	str_status = handle_stopped(stat_val);
	// else if (WIFSIGNALED(stat_val))
	// 	str_status = handle_signaled(stat_val);
	// else
	// 	str_status = twl_strdup("Unknown");
	return (str_status);
}
