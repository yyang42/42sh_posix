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

#ifndef JOB_CONTROL_JOBEXEC_H
# define JOB_CONTROL_JOBEXEC_H

# include "basics.h"
# include "job_control/job_mgr.h"

void				jobexec_fork_exec(t_lst *all_tokens, void *exec_ctx,
					void (wait_fn)(int pid),
					void (execve_fn)(void *ctx));

#endif
