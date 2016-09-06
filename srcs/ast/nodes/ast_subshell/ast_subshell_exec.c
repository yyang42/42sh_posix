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

#include "ast/nodes/ast_subshell.h"
#include "ast/nodes/ast_compound_list.h"

static void			ast_subshell_fork_exec(t_ast_subshell *this)
{
	int				pid;
	int				res;

	pid = shenv_utils_fork();
	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		ast_compound_list_exec(this->ast_compound_list);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		waitpid(pid, &res, 0);
		if (WIFEXITED(res))
		{
			shenv_singleton()->last_exit_code = WEXITSTATUS(res);
		}
		else if (WIFSIGNALED(res))
		{
			shenv_singl_error(143, "%d Terminated: %d", pid, WTERMSIG(res));
		}
	}
}

void				ast_subshell_exec(t_ast_subshell *this)
{
	shenv_set_cur_token(shenv_singleton(), token_mgr_first(this->tokens));
	ast_subshell_fork_exec(this);
}
