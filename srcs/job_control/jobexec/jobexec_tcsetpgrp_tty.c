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

void				jobexec_tcsetpgrp_tty(t_jobexec *je)
{
	if (!jobexec_fork_exec_should_tcset(je))
		return ;
	if (tcsetpgrp(0, getpid()) >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 0");
	}
	else if (tcsetpgrp(1, getpid()) >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 1");
	}
	else if (tcsetpgrp(2, getpid())  >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 2");
	}
	else
	{
		LOG_ERROR("tcsetpgrp: %s", strerror(errno));
	}
}
