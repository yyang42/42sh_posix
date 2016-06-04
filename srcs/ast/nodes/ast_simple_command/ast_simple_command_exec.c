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
#include "ast/nodes/ast_redir.h"
#include "job_control/job_mgr.h"
#include "job_control/jobexec.h"

static void			ast_simple_command_exec_print_log(t_ast_simple_command *cmd)
{
	char			*cmd_str;

	cmd_str = token_mgr_strjoin(cmd->cmd_tokens_deep_copy, " ");
	LOG_INFO("simple command exec: %s", cmd_str);
	free(cmd_str);
}

static void			ast_simple_command_exec_with_redirs(t_ast_simple_command *cmd)
{
	ast_simple_command_exec_print_log(cmd);
	ast_redir_fd_mgr_init(cmd->redir_fds, cmd->redir_items);
	if (shenv_singleton()->last_exit_code != 0)
	{
		if (ast_simple_command_is_special_builtin(cmd))
			exit(1);
		return ;
	}
	ast_simple_command_exec_tokens(cmd);
	ast_redir_fd_mgr_close_clear(cmd->redir_fds);
}

void				ast_simple_command_exec_inner(t_ast_simple_command *cmd)
{
	if (!shenv_should_continue_exec(shenv_singleton()))
		return ;
	shenv_singleton()->info.saved_last_exit = shenv_singleton()->last_exit_code;
	shenv_singleton()->last_exit_code = EXIT_SUCCESS;
	shenv_set_cur_token(shenv_singleton(), token_mgr_first(cmd->cmd_tokens_deep_copy));
	ast_simple_command_expan(cmd);
	job_mgr_wait_update(shenv_singleton()->jobs);
	ast_simple_command_exec_assign(cmd);
	if (shenv_singleton()->last_exit_code != 0 && twl_lst_len(cmd->cmd_tokens_deep_copy) == 0)
	{
		exit(1);
		return ;
	}
	if (shenv_shflag_enabled(shenv_singleton(), "xtrace") && twl_lst_len(cmd->cmd_tokens_expanded))
		token_mgr_xtrace_print(cmd->cmd_tokens_expanded);
	ast_simple_command_exec_with_redirs(cmd);
	shvar_mgr_clear_assign_value(shenv_singleton()->shenv_shvars);
	token_mgr_del(cmd->cmd_tokens_expanded);
	cmd->cmd_tokens_expanded = NULL;
}




static void         block_sigchld(void)
{
    sigset_t        blockMask;

    LOG_DEBUG("block SIGCHLD");
    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    if (sigprocmask(SIG_BLOCK, &blockMask, NULL) == -1)
        LOG_ERROR("sigprocmask");

}

static void         unblock_sigchld(void)
{
    sigset_t        blockMask;

    LOG_DEBUG("unblock SIGCHLD");
    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    if (sigprocmask(SIG_UNBLOCK, &blockMask, NULL) == -1)
        LOG_ERROR("sigprocmask");

}

static void         ast_utils_exec_string_with_sig_handling(t_ast_simple_command *cmd)
{
    block_sigchld();
    jobexec_fork_utils_init_sigchld_handler();
    ast_simple_command_exec_inner(cmd);;
    unblock_sigchld(); /* TODO: Find a better way */
    block_sigchld(); /* TODO: Find a better way */
    return ;
    // signal(SIGCHLD, SIG_IGN);
}

void				ast_simple_command_exec(t_ast_simple_command *cmd)
{

    LOG_DEBUG("ast_simple_command_exec");
    if (shenv_singleton()->shenv_is_function_or_script)
		ast_simple_command_exec_inner(cmd);
    else
        ast_utils_exec_string_with_sig_handling(cmd);
}
