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

#include "async/job.h"

char				*job_status_str(t_job *this)
{
	char			*str_status;

	if (this->status == JOB_RUNNING)
		str_status = "Running";
	else if (this->status == JOB_TERMINATED)
		str_status = "Terminated";
	else
		str_status = "Unknown";
	return (str_status);
}
