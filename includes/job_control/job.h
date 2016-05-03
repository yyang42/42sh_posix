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

#ifndef JOB_CONTROL_JOB_H
# define JOB_CONTROL_JOB_H

# include "basics.h"
# include <termios.h>

typedef enum s_job_status
{
	JOB_STOPPED,
	JOB_RUNNING,
	JOB_DONE,
	JOB_CONTINUED,
	JOB_TERMINATED,
} t_job_status;

typedef struct		s_job
{
	int				job_id;
	char			sign;
	pid_t			pid;
	int				status;
	int				job_status;
	char			*cmd_str;
	int				end_pid;
	int				stopped_signal;
  	struct termios	tmodes;      /* saved terminal modes */
}					t_job;

t_job				*job_new(pid_t pid, t_lst *str_tokens);
t_job				*job_new_from_tokens(pid_t pid, t_lst *tokens);
void				job_del(t_job *job);
void				job_del_void(void *job);

char				*job_status_str(t_job *this);
char				*job_status_str_long(t_job *this, bool incl_pid);

int					job_utils_get_signum(char *sigstr);
bool				job_has_terminated(t_job *this);
void				job_print(t_job *this, int flags);

void				job_utils_waitpid(pid_t pid, int *res);
bool				job_utils_is_job_control_active(void);

bool				job_exec_update_status(t_job *job);
pid_t				job_get_kill_pid(t_job *job);
void	         	job_put_in_fg(t_job *job);
void				job_print_if_stopped(t_job *job);

#endif
