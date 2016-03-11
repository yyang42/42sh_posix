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

#include "ast/ast.h"

int					ast_exec_tokens_with_fork(t_lst *tokens)
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
		shenv_singleton_setter(shenv_new());
		ast_exec_tokens(tokens);
		exit(0);
	}
	else
	{
		waitpid(pid, &res, 0);
		// if (WIFEXITED(res))
		// 	return (WEXITSTATUS(res));
	}
	return (1);
}
