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

#ifndef JOB_CONTROL_JOB_MGR_H
# define JOB_CONTROL_JOB_MGR_H

# include "basics.h"
# include "job_control/job.h"
# include "shenv/shenv.h"

t_lst				*job_mgr_new(void);
void				job_mgr_del(t_lst *jobs);
void				job_mgr_add(t_lst *jobs, t_job *job);
t_job				*job_mgr_pop(t_lst *jobs, t_job *job);
int					job_mgr_remove(t_lst *jobs, t_job *job);
void				job_mgr_print(t_lst *jobs);

int					job_mgr_env_push(t_job *job);
void				job_mgr_wait_update(t_lst *jobs);

t_job 				*job_mgr_find_by_job_id(t_lst *jobs, char *job_str_id);
t_job 				*job_mgr_find_by_pid(t_lst *jobs, int pid);
t_job 				*job_mgr_find_by_str_pid(t_lst *jobs, char *str_pid);
t_job 				*job_mgr_find_by_pid_perc_job_id(t_lst *jobs, char *str);
void				job_mgr_update_sign(t_lst *jobs);
void				job_mgr_sort_by_id(t_lst *jobs);
void				job_mgr_sort_by_status(t_lst *jobs);

#endif
