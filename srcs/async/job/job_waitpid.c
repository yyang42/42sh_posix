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
#include "async/job.h"
#include "signal.h"

pid_t				job_waitpid(t_job *this)
{
	pid_t			stat_val;

	stat_val = 0;
	waitpid(this->pid, &stat_val, WNOHANG | WCONTINUED | WUNTRACED);
	return (stat_val);
}
