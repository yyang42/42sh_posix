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

static void sig_received(void)
{
	LOG_INFO("sig_received trigged");
	if (shenv_shflag_enabled(shenv_singleton(), "i"))
	{
		twl_printf("\n");
	}
	else if (shenv_shflag_enabled(shenv_singleton(), "i"))
	{
		exit(130);
	}
}

void				job_utils_waitpid(pid_t pid, int *res_ptr)
{
	int				res;
	pid_t			waitpid_ret;

	LOG_INFO("waitpid(%d) start", pid);
 	waitpid_ret = waitpid(pid, &res, WUNTRACED);
	LOG_INFO("waitpid(%d) end", pid);
	LOG_INFO("waitpid ret: %d", waitpid_ret);
 	if (waitpid_ret == -1)
 	{
 		shenv_singl_error(1, "waitpid: %s", strerror(errno));
		LOG_ERROR("waitpid error: pid: %d: %s", pid, strerror(errno));
 	}
 	else if (waitpid_ret == pid)
 	{
        if (WIFEXITED(res))
        {
			shenv_singleton()->last_exit_code = WEXITSTATUS(res);
			LOG_INFO("exit status: %d", shenv_singleton()->last_exit_code);
    	}
    	if (WIFCONTINUED(res))
    	{
    		LOG_INFO("WIFCONTINUED");
    	}
		else if (WIFEXITED(res))
		{
			LOG_INFO("WIFEXITED");
		}
		else if (WIFSIGNALED(res))
		{
        	handle_signal(WTERMSIG(res));
			LOG_INFO("WIFSIGNALED: %d", WTERMSIG(res));
			if (WTERMSIG(res) == SIGINT)
			{
				sig_received();
			}
		}
		else if (WIFSTOPPED(res))
		{
			LOG_INFO("WIFSTOPPED");
		}
		else if (WSTOPSIG(res))
		{
			LOG_INFO("WSTOPSIG");
		}
		else
		{
			LOG_INFO("UNKNOWN");
		}
 	}
 	if (res_ptr)
 	{
 		*res_ptr = res;
 		LOG_INFO("res     hex: %lx", res);
 		LOG_INFO("res_ptr hex: %lx", *res_ptr);
 	}
}
