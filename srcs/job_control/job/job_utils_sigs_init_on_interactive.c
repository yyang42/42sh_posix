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
#include "shsignal/shsignal_mgr.h"
#include "data.h"
#include <sys/wait.h>

static void			handle_notify_do(pid_t pid, int status)
{
	t_job			*job;

	job = job_mgr_find_by_pid(shenv_singleton()->jobs, pid);
	if (job)
	{
		job->status = status;
		job_exec_update_status(job);
		if (job_has_terminated(job))
		{
			job_mgr_remove(shenv_singleton()->jobs, job);
		}
	}
}

static void			handle_notify_one(pid_t start_pid)
{
	pid_t			pid;
	int				status;

	while ((pid = waitpid(start_pid, &status, WNOHANG)) > 0)
		handle_notify_do(pid, status);
	while ((pid = waitpid(start_pid, &status, WNOHANG | WUNTRACED | SA_NOCLDWAIT)) > 0)
		handle_notify_do(pid, status);
}


void				handle_notify(int sig)
{
	t_lst			*jobs_copy;
	t_job			*job;

	if (!shenv_flag_exist(shenv_singleton(), "b"))
		return ;
	job_mgr_update_sign(shenv_singleton()->jobs);
	jobs_copy = twl_lst_copy(shenv_singleton()->jobs, NULL);
	while ((job = twl_lst_pop_front(jobs_copy)))
	{
		handle_notify_one(job->pid);
	}
	twl_lst_del(jobs_copy, NULL);
	(void)sig;
}

void				job_utils_sigs_init_on_interactive(void)
{
	if (!shenv_singleton()->is_interactive_shell)
		return ;
	LOG_INFO("ignore signals")
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCHLD, handle_notify);
}
