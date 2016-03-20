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

t_job				*job_new(pid_t pid, char *cmd_str, t_lst *tokens)
{
	t_job					*this;
	static long long int	job_id = 1;

	this = twl_malloc_x0(sizeof(t_job));
	this->job_id = job_id;
	this->pid = pid;
	this->cmd_str = twl_strdup(cmd_str);
	this->tokens = twl_lst_copy(tokens, NULL);
	job_id++;
	return (this);
}
