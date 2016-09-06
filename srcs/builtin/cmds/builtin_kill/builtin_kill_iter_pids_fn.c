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

#include "builtin/builtin.h"
#include "builtin/cmds/builtin_kill.h"
#include "twl_logger.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"
#include "job_control/job_mgr.h"

static t_job		*get_job_by_id(char *job_id_str)
{
	if (*job_id_str != '%')
		return (NULL);
	job_id_str++;
	return (job_mgr_find_by_job_id(shenv_singleton()->jobs, job_id_str));
}

static bool			iter_pids_fn_cnt(t_token *token, int signum,
		int *pid, t_job **job)
{
	if ((*job = get_job_by_id(((t_token *)token)->text)))
	{
		*pid = (*job)->pid;
		builtin_kill_update_job(*job, signum);
	}
	else if (twl_str_is_num(token->text))
	{
		*pid = twl_atoi(token->text);
		if (kill(*pid, 0) == -1)
		{
			shenv_singl_error(EXIT_FAILURE,
				"kill: (%s) - No such process", (token->text));
			return (false);
		}
	}
	else
	{
		shenv_singl_error(EXIT_FAILURE,
	"kill: %s: arguments must be process or job IDs", (token->text));
		return (false);
	}
	return (true);
}

void				builtin_kill_iter_pids_fn(void *token, void *signum)
{
	int				pid;
	t_job			*job;

	if (!iter_pids_fn_cnt(token, *(int *)signum, &pid, &job))
		return ;
	if ((job = job_mgr_find_by_pid(shenv_singleton()->jobs, pid)))
		pid = job_get_kill_pid(job);
	LOG_INFO("kill: %s(%d), pid=%d", shsignal_mgr_get_signame(data_signals(),
				*(int *)signum), *(int *)signum, pid);
	if (kill(pid, *(int *)signum) == -1)
		shenv_singl_error(1, "kill: %s", strerror(errno));
}
