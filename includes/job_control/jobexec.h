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

typedef void (t_je_wait_fn)(int pid, void *ctx);
typedef void (t_je_execve_fn)(void *ctx);

typedef struct		s_jobexec
{
	t_lst			*all_tokens;
	void			*exec_ctx;
	t_je_wait_fn	*wait_fn;
	t_je_execve_fn	*execve_fn;
	bool			is_bg_job;
} 					t_jobexec;

void				jobexec_fork_exec(t_jobexec *je);
void				jobexec_fork_exec_non_interactive(t_jobexec *je);
void				jobexec_fork_exec_interactive(t_jobexec *je);
void				jobexec_fork_exec_interactive_void(void *je);
void				jobexec_fork_exec_interactive_job(t_jobexec *je);
void				jobexec_fork_exec_interactive_job_sig_wrapper(t_job *job, void *ctx,
					void (exec_interactive_fn)(void *ctx));
void				jobexec_fork_exec_execve_fn(t_jobexec *je);
void				jobexec_fork_exec_wait_fn(t_jobexec *je, pid_t pid);
bool				jobexec_fork_exec_should_tcset(t_jobexec *je);

#endif
