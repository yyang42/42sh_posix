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

#include "ast/ast.h"
#include "token/token_mgr.h"
#include "job_control/job_mgr.h"
#include "data.h"

static void         handle_job(int si_code, t_job *job)
{
    if (si_code == CLD_STOPPED)
    {
        utils_tcsetpgrp_for_tty_012(getpid());
        if(kill(job_get_kill_pid(job), SIGTSTP) < 0)
            LOG_ERROR("kill: %s", strerror(errno));
        job_mgr_env_push(job);
    }
    if (job_mgr_find_by_pid(shenv_singleton()->jobs, job->pid)
        && shenv_shflag_enabled(shenv_singleton(), "notify"))
    {
        if (si_code == CLD_EXITED || si_code == CLD_STOPPED
            || si_code == CLD_KILLED)
        {
            LOG_INFO("si_code=CLD_EXITED, job->id=%d", job->pid);
            job_print(job, 0, STDERR_FILENO);
            job_mgr_remove(shenv_singleton()->jobs, job);
        }
    }
}


static void			sigstp_catcher(int signum, siginfo_t *info, void *vp)
{
    t_job           *job;
    pid_t           gid;
 //    pid_t			pid;

    // twl_printf("======================================****************************");
    return ;
	// while ((pid = waitpid(-1, 0, WNOHANG)) > 0)
	// {
 //    	twl_printf("pid: %d\n", pid);
	// }
	// return ;
    gid = getpgid(info->si_pid);
    LOG_INFO("signum: %d, Signal %d from PID %d, code: %d, value: %d: gid: %d",
	signum, info->si_signo, (int)info->si_pid, info->si_code, info->si_value, gid);
    LOG_INFO("child stopped: %d", info->si_pid);
    LOG_INFO("data_tmp_jobs() len: %d", twl_lst_len(data_tmp_jobs()));
    job = job_mgr_find_by_pid(data_tmp_jobs(), info->si_pid);
    if (!job)
    {
        LOG_INFO("search in shenv->jobs");
        job = job_mgr_find_by_pid(shenv_singleton()->jobs, info->si_pid);
    }
    if (job)
    {
        LOG_DEBUG("info->si_pid: %d", info->si_pid);
        LOG_DEBUG("job->pid: %d", job->pid);
        handle_job(info->si_code, job);
    }
    else
    {
        LOG_INFO("pid not found: %d", info->si_pid);
    }
    (void)vp;
    (void)signum;
}

static void         block_sigchld(void)
{
    sigset_t        blockMask;

    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    if (sigprocmask(SIG_BLOCK, &blockMask, NULL) == -1)
        LOG_ERROR("sigprocmask");

}

static void         unblock_sigchld(void)
{
    sigset_t        blockMask;

    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    if (sigprocmask(SIG_UNBLOCK, &blockMask, NULL) == -1)
        LOG_ERROR("sigprocmask");

}

static void         sig_handler_init(void)
{
    struct sigaction sa;
    struct sigaction oldsa;
    static bool     signal_initialized = false;

    if (signal_initialized)
        return ;

    signal_initialized = true;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigstp_catcher;
    sigemptyset(&sa.sa_mask);
    LOG_INFO("set sig_handler_init");
    if (sigaction(SIGCHLD, &sa, &oldsa) != 0)
    {
        int errnum = errno;
        LOG_ERROR("Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
        exit(1);
        (void)errnum;
    }
}

static int			build_flags(void)
{
	int				flags;

	flags = 0;
	if (shenv_singleton()->shenv_prog_flags & SHENV_FLAG_AST)
	{
		flags |= AST_FLAG_NO_EXEC;
	}
	return (flags);
}

void				ast_utils_exec_string(char *input, int line)
{
	t_ast			*ast;

	// twl_printf("=================\n");
	// return ;
	block_sigchld();
	// sig_handler_init();
	// block_sigchld();
	sig_handler_init();
	ast = ast_new_from_string(input, build_flags(), line);
	ast_print_error(ast);
	ast_del(ast);
	unblock_sigchld();
}
