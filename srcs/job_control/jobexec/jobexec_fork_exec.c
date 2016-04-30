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

#include "job_control/jobexec.h"

void				jobexec_fork_exec(t_jobexec *je)
{
	if (shenv_singleton()->is_interactive_shell
		&& !shenv_singleton()->shenv_is_inside_job_control)
	{
		jobexec_fork_exec_interactive_sig_wrapper(je);
	}
	else
	{
		jobexec_fork_exec_non_interactive(je);
	}
}
