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

void				jobexec_fork_exec(t_lst *all_tokens, void *exec_ctx,
					void (wait_fn)(int pid, void *ctx),
					void (execve_fn)(void *ctx))
{
	if (shenv_singleton()->is_interactive_shell)
		jobexec_fork_exec_interactive(all_tokens, exec_ctx, wait_fn, execve_fn);
	else
		jobexec_fork_exec_non_interactive(all_tokens, exec_ctx, wait_fn, execve_fn);
}
