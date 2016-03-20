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
#include <errno.h>
#include "async/job.h"
#include "signal.h"

void				job_waitpid_update(t_job *this)
{
	this->end_pid = waitpid(this->pid, &this->status, WNOHANG | WUNTRACED);
	if (this->end_pid == -1 && errno != ECHILD)
	{
        twl_dprintf(2, "waitpid error: %d\n", this->pid);
		// exit(EXIT_FAILURE);
	}
}
