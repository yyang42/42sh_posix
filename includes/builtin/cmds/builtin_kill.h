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

#ifndef BUILTIN_KILL_H
# define BUILTIN_KILL_H

# include "basics.h"
# include "shenv/shenv.h"
# include "shsignal/shsignal.h"
# include "job_control/job.h"
# include "job_control/job_mgr.h"

void				builtin_kill_exec(t_lst *tokens, t_shenv *env);
void				builtin_kill_print_signals(void);
void				builtin_kill_print_usage(void);
void				builtin_kill_update_job(t_job *job, int signum);

void				builtin_kill_iter_pids_fn(void *token, void *signum);

#endif
