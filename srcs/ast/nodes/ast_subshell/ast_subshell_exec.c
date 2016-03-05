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

	pid = fork();
	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		ast_compound_list_exec(this->ast_compound_list);
		exit(0);
	}
	else
	{
		wait(&res);
    	if (WIFEXITED(res))
			shenv_singleton()->info.last_exit_status = WEXITSTATUS(res);
	}
}

void				ast_subshell_exec(t_ast_subshell *this)
{
	ast_subshell_fork_exec(this);
}
