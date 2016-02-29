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

#include "async/job.h"
#include "signal.h"

char				*job_status_str(t_job *this)
{
	char			*str_status;
	int				pid;
	int				stat_val;

	pid = this->pid;
	waitpid(pid, &stat_val, WNOHANG);
	if (WIFEXITED(stat_val))
	{
		if (WEXITSTATUS(stat_val) == 0)
			twl_asprintf(&str_status, "Done");
		else
			twl_asprintf(&str_status, "Done(%d)", WEXITSTATUS(stat_val));
	}
	else if (WIFSTOPPED(stat_val))
		twl_asprintf(&str_status, "WSTOPSIG(%d)", WSTOPSIG(stat_val));
	else if (WIFSIGNALED(stat_val))
		twl_asprintf(&str_status, "WTERMSIG(%d)", WTERMSIG(stat_val));
	else
		str_status = twl_strdup("Unknown");
	// if (this->status == JOB_RUNNING)
	// 	str_status = twl_strdup("Running");
	// else if (this->status == JOB_TERMINATED)
	// 	str_status = twl_strdup("Terminated");
	// else
	return (str_status);
}
