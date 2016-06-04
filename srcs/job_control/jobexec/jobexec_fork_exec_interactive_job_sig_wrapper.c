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
    shenv_singleton()->shenv_foreground_job = job;
    exec_interactive_fn(job, ctx);
}
