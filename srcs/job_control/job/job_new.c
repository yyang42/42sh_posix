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

#include "job_control/job.h"
#include "token/token_mgr.h"

t_job				*job_new(pid_t pid, t_lst *str_tokens)
{
	t_job					*this;

	this = twl_malloc_x0(sizeof(t_job));
	this->job_id = 0;
	this->pid = pid;
	this->cmd_str = twl_lst_strjoin(str_tokens, " ");
	this->stopped_signal = 0;
	this->job_status = JOB_RUNNING;
	return (this);
}
