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
#include "logger.h"
#include "shsignal/shsignal.h"
#include <setjmp.h>
#include <sys/wait.h>

static jmp_buf jump_buf;

static void         sigtstp_handler(int sig)
{
    LOGGER_INFO("SIGTSTP handler: %d", sig);
    longjmp(jump_buf, 1);
}

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

void				ast_simple_command_execve_parent(t_ast_simple_command *cmd, pid_t pid)
{
	signal(SIGTSTP, sigtstp_handler);
	setpgid(pid, pid);
    if (setjmp(jump_buf) == 0)
    {
		ast_simple_command_execve_parent_wait(pid);
    }
    else
    {
		if (kill(-pid, SIGTSTP) == -1)
			perror("kill");
    	ast_list_item_exec_async_parent_create_job(cmd->full_command_tokens, pid);
    }
	signal(SIGTSTP, SIG_IGN);
}
