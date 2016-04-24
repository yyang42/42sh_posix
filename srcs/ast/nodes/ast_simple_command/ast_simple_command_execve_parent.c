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

#include "ast/nodes/ast_list_item.h"
#include "ast/nodes/ast_simple_command.h"
#include "twl_logger.h"
#include "shsignal/shsignal.h"
#include <sys/wait.h>
#include "shsignal/shsignal_mgr.h"
#include "data.h"

void				ast_simple_command_execve_parent(t_lst *str_tokens, pid_t pid)
{
    t_job           *job;

    if (shenv_singleton()->shenv_is_inside_job_control)
    {
        job_utils_waitpid(pid);
    }
    else
    {
        job = job_new(pid, str_tokens);
        job_put_in_fg(job);
    }
}
