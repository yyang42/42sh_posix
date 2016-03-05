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

#ifndef ASYNC_JOB_MGR_H
# define ASYNC_JOB_MGR_H

# include "basics.h"
# include "async/job.h"
# include "shenv/shenv.h"

t_lst				*job_mgr_new(void);
void				job_mgr_del(t_lst *jobs);
void				job_mgr_add(t_lst *jobs, t_job *job);
void				job_mgr_remove(t_lst *jobs, t_job *job);
void				job_mgr_print(t_lst *jobs);

void				job_mgr_env_print(void);
void				job_mgr_env_push(t_job *job);

#endif
