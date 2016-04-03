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
#include <sys/wait.h>

void				ast_simple_command_execve_parent_wait(pid_t pid)
{
	int				res;
	pid_t			waitpid_ret;

 	waitpid_ret = waitpid(pid, &res, 0);
 	if (waitpid_ret == -1)
 	{
 		perror("waitpid");
 	}
 	else if (waitpid_ret == pid)
 	{
        handle_signal(res);
        if (WIFEXITED(res))
        {
			shenv_singleton()->last_exit_code = WEXITSTATUS(res);
			LOGGER_INFO("exit status: %d", shenv_singleton()->last_exit_code);
    	}
 	}
}
