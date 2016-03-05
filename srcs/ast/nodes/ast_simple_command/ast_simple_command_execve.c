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
#include "signals.h"

static void		fork_and_execute(char *path, t_lst *tokens, char **env)
{
	int				pid;
	int				res;
	char			**args;

	args = token_mgr_to_str_arr(tokens);
	pid = fork();
	if (pid == -1)
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	else if (pid == 0)
	{
		execve(path, args, env);
		perror(path);
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGKILL, SIG_IGN);
		wait(&res);
		signal(SIGINT, SIG_DFL);
		signal(SIGKILL, SIG_DFL);
		handle_signal(res);
    	if (WIFEXITED(res))
			shenv_singleton()->info.last_exit_status = WEXITSTATUS(res);
	}
	twl_arr_del(args, NULL);
}

void			ast_simple_command_execve(char *path, t_lst *tokens, char **env)
{
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			fork_and_execute(path, tokens, env);
		else
			error_permission_denied(path);
	}
	else
	{
		error_command_not_found(token_mgr_first(tokens)->text);
	}
}
