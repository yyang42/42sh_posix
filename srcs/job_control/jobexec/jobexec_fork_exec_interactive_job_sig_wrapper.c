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

#include "job_control/jobexec.h"
#include "utils.h"
#include "data.h"

void				jobexec_fork_exec_interactive_job_sig_wrapper(t_job *job, void *ctx,
					void (exec_interactive_fn)(t_job *job, void *ctx))
{
    LOG_INFO("jobexec_fork_exec_interactive_job_sig_wrapper");
    LOG_INFO("tmp jobs len: %d: job->pid: %d (before exec)", twl_lst_len(data_tmp_jobs()), job->pid);
    twl_lst_push_back(data_tmp_jobs(), job);
    LOG_INFO("tmp jobs len: %d: job->pid: %d (before 2 exec)", twl_lst_len(data_tmp_jobs()), job->pid);
    exec_interactive_fn(job, ctx);
    job_mgr_pop(data_tmp_jobs(), job);
    LOG_INFO("tmp jobs len: %d: job->pid: %d (after exec)", twl_lst_len(data_tmp_jobs()), job->pid);
    if (job_mgr_find_by_pid(data_tmp_jobs(), job->pid))
        job_del(job);
}
