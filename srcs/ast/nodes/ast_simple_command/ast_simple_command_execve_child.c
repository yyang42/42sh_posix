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

#include "ast/nodes/ast_simple_command.h"
#include "job_control/job.h"

void				ast_simple_command_execve_child(t_lst *argv_lst, char *path)
{
	// TODO: also apply this on other use case of shenv_execve?
	// job_utils_sigs_dfl_on_interactive_for_chld_proc();
	shenv_execve(shenv_singleton(), path, argv_lst);
}
