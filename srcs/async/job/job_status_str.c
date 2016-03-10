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

char				*job_status_str(t_job *this)
{
	char			*str_status;
	int				pid;
	int				stat_val;
	// char			*temp;

	pid = this->pid;
	// temp = twl_strdup("Done");
	waitpid(pid, &stat_val, WNOHANG | WCONTINUED | WUNTRACED);
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
		str_status = handle_signaled(stat_val);
	else
		str_status = twl_strdup("Unknown");
	return (str_status);
}
