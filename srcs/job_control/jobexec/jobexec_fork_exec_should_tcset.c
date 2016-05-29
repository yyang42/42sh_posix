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

bool				jobexec_fork_exec_should_tcset(t_jobexec *je)
{
	return ((shenv_singleton()->shenv_fork_level == 0)
		&& (utils_get_current_tty() > -1)
		&& !je->is_bg_job);
}
