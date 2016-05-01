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

bool				jobexec_fork_exec_should_tcset(t_jobexec *je)
{
	LOG_DEBUG("jobexec_fork_exec_should_tcset: fork level: %d\n", shenv_singleton()->shenv_fork_level);
	LOG_DEBUG("jobexec_fork_exec_should_tcset: isatty    : %d\n", isatty(0));
	LOG_DEBUG("jobexec_fork_exec_should_tcset: is_bg_job : %d\n", je->is_bg_job);
	return ((shenv_singleton()->shenv_fork_level == 0)
		&& isatty(0)
		&& !je->is_bg_job);
}
