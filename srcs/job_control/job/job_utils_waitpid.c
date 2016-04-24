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

void				job_utils_waitpid(pid_t pid)
{
	int				res;
	pid_t			waitpid_ret;

 	waitpid_ret = waitpid(pid, &res, 0);
 	if (waitpid_ret == -1)
 	{
 		shenv_singl_error(1, "waitpid: %s", strerror(errno));
		LOG_ERROR("waitpid error: pid: %d", pid);
 	}
 	else if (waitpid_ret == pid)
 	{
        handle_signal(res);
        if (WIFEXITED(res))
        {
			shenv_singleton()->last_exit_code = WEXITSTATUS(res);
			LOG_INFO("exit status: %d", shenv_singleton()->last_exit_code);
    	}
 	}
}
