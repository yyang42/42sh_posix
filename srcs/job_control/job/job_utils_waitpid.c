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
#include "shenv/shenv.h"
#include "shsignal/shsignal.h"
#include "job_control/job_mgr.h"
#include "data.h"

static void         handle_notify(pid_t pid)
{
	t_job			*job;

	LOG_DEBUG("================= 3 1");
    job = job_mgr_find_by_pid(shenv_singleton()->jobs, pid);
    if (job)
    {
		LOG_DEBUG("================= 3 2");
    }
    if (job && shenv_shflag_enabled(shenv_singleton(), "notify"))
    {
    	LOG_DEBUG("================= 4");
        // if (si_code == CLD_EXITED || si_code == CLD_STOPPED
        //     || si_code == CLD_KILLED)
        // {
            LOG_INFO("si_code=CLD_EXITED, job->id=%d", pid);
            job_print(job, 0, STDERR_FILENO);
            job_mgr_remove(shenv_singleton()->jobs, job);
        // }
    }
}

static void			sigstp_catcher(int pid)
{
    t_job           *job;
 //    pid_t           gid;

 //    gid = getpgid(pid);
 //    LOG_INFO("signum: %d, Signal %d from PID %d, code: %d, value: %d: gid: %d",
	// signum, info->si_signo, (int)pid, info->si_code, info->si_value, gid);
 //    LOG_INFO("child stopped: %d", pid);
    LOG_INFO("data_tmp_jobs() len: %d", twl_lst_len(data_tmp_jobs()));
    job = job_mgr_find_by_pid(data_tmp_jobs(), pid);
    if (!job)
    {
        LOG_INFO("search in shenv->jobs");
        job = job_mgr_find_by_pid(shenv_singleton()->jobs, pid);
    }
    if (job)
    {
        LOG_DEBUG("pid: %d", pid);
        LOG_DEBUG("job->pid: %d", job->pid);
        job_mgr_env_push(job);
        // job_mgr_pop(data_tmp_jobs(), job);
        // handle_job(sig, job);
    }
    else
    {
        LOG_INFO("pid not found: %d", pid);
    }
    // (void)vp;
    // (void)signum;
}


void				job_utils_waitpid(pid_t pid, int *res_ptr)
{
	int				res;
	pid_t			waitpid_ret;

	LOG_INFO("waitpid(%d) start", pid);
 	waitpid_ret = waitpid(pid, &res, WUNTRACED);
	LOG_INFO("waitpid(%d) end", pid);
	LOG_INFO("waitpid ret: %d", waitpid_ret);
 	if (waitpid_ret == -1)
 	{
 		shenv_singl_error(1, "waitpid: %s", strerror(errno));
		LOG_ERROR("waitpid error: pid: %d: %s", pid, strerror(errno));
 	}
 	else if (waitpid_ret == pid)
 	{
        if (WIFEXITED(res))
        {
			shenv_singleton()->last_exit_code = WEXITSTATUS(res);
			LOG_INFO("exit status: %d", shenv_singleton()->last_exit_code);
    	}
    	if (WIFCONTINUED(res))
    	{
    		LOG_INFO("WIFCONTINUED");
    	}
		else if (WIFEXITED(res))
		{
			LOG_INFO("WIFEXITED");
		}
		else if (WIFSIGNALED(res))
		{
			LOG_INFO("WIFSIGNALED: %d", WTERMSIG(res));
        	handle_exec_signal(WTERMSIG(res));
		}
		else if (WIFSTOPPED(res))
		{
			LOG_INFO("WIFSTOPPED");
			sigstp_catcher(pid);
		}
		else if (WSTOPSIG(res))
		{
			LOG_INFO("WSTOPSIG");
		}
		else
		{
			LOG_INFO("UNKNOWN");
		}

		LOG_DEBUG("================= 1");
 		if (WIFSTOPPED(res) || WIFEXITED(res))
 		{
		LOG_DEBUG("================= 2");
 			handle_notify(pid);
 		}

 	}
 	if (res_ptr)
 	{
 		*res_ptr = res;
 		LOG_INFO("res     hex: %lx", res);
 		LOG_INFO("res_ptr hex: %lx", *res_ptr);
 	}
}
