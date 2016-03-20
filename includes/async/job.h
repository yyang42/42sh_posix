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

#ifndef ASYNC_JOB_H
# define ASYNC_JOB_H

# include "basics.h"
/*

	One of the following strings (in the POSIX locale):
	Running
	Indicates that the job has not been suspended by a signal and has not exited.
	Done
	Indicates that the job completed and returned exit status zero.
	Done(code)
	Indicates that the job completed normally and that it exited with the specified non-zero exit status, code, expressed as a decimal number.
	Stopped
	Indicates that the job was suspended by the SIGTSTP signal.
	Stopped (SIGTSTP)
	Indicates that the job was suspended by the SIGTSTP signal.
	Stopped (SIGSTOP)
	Indicates that the job was suspended by the SIGSTOP signal.
	Stopped (SIGTTIN)
	Indicates that the job was suspended by the SIGTTIN signal.
	Stopped (SIGTTOU)
	Indicates that the job was suspended by the SIGTTOU signal.
	The implementation may substitute the string Suspended in place of Stopped. If the job was terminated by a signal, the format of <state> is unspecified, but it shall be visibly distinct from all of the other <state> formats shown here and shall indicate the name or description of the signal causing the termination.

*/

typedef struct		s_job
{
	t_lst			*tokens;
	int				job_id;
	pid_t			pid;
	int				status;
	char			*cmd_str;
	int				end_pid;
}					t_job;

t_job				*job_new(pid_t pid, char *cmd_str, t_lst *tokens);
void				job_del(t_job *job);
void				job_del_void(void *job);

char				*job_status_str(t_job *this);
void				job_waitpid_update(t_job *this);
char				*job_status_str_long(t_job *this, bool incl_pid);

#endif
