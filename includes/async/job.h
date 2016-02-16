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

typedef enum		e_job_status
{
	RUNNING,
	TERMINATED,
}					t_job_status;

typedef struct		s_job
{
	int				job_id;
	int				pid;
	t_job_status	status;
	char			*command;
}					t_job;

t_job				*job_new(void);
void				job_del(t_job *job);

#endif
