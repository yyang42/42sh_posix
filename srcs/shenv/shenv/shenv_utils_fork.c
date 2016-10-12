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

#include "twl_opt_elem.h"
#include "shenv/shenv.h"
#include "job_control/job.h"

pid_t					shenv_utils_fork(void)
{
	pid_t			pid;
	int				errno_save;

	pid = fork();
	errno_save = errno;
	if (pid == 0)
	{
		;
	}
	else if (pid == -1)
	{
		shenv_singl_error(2, "cannot fork: %s", twl_strerror(errno_save));
		LOG_ERROR("cannot fork: %s", twl_strerror(errno_save));
	}
	errno = errno_save;
	return (pid);
}
