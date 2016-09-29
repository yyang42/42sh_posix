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

#include "job_control/job_mgr.h"
#include "twl_stdlib.h"

t_job				*job_mgr_find_by_str_pid(t_lst *jobs, char *str_pid)
{
	if (twl_str_is_num(str_pid))
		return (job_mgr_find_by_pid(jobs, twl_atoi(str_pid)));
	return (NULL);
}
