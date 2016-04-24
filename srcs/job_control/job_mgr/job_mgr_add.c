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

#include "job_control/job_mgr.h"

void				job_mgr_add(t_lst *jobs, t_job *job)
{
	LOG_INFO("async exec: %s", job->cmd_str);
	if (shenv_singleton()->is_interactive_shell)
		twl_dprintf(2, "[%d] %d\n", job->job_id, job->pid);
	twl_lst_push_back(jobs, job);
}
