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
		// twl_lst_clear(shenv_singleton()->jobs, job_del_void); // cause read: input/outpur error
	}
	else if (pid == -1)
	{
		shenv_singl_error(2, "cannot fork: %s", strerror(errno_save));
		LOG_ERROR("cannot fork: %s", strerror(errno_save));
	}
	errno = errno_save;
	return (pid);
}
