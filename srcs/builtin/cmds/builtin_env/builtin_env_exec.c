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

#include "builtin/cmds/builtin_env.h"
#include "ast/ast.h"

int				ast_exec_string_in_fork(char *input)
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
		ast_exec_string(input);
		exit(0);
	}
	else
	{
		wait(&res);
		if (WIFEXITED(res))
			return (WEXITSTATUS(res));
	}
	return (1);
}

static int			exec_remaining_command(t_lst *tokens, t_shenv *env)
{
	int				exit_code;
	char			*input;


	if (token_mgr_first_equ(tokens, "-i"))
	{
		twl_lst_pop_front(tokens);
		input = token_mgr_strjoin(tokens, " ");
		exit_code = ast_exec_string_in_fork(input);
	}
	else
	{
		input = token_mgr_strjoin(tokens, " ");
		exit_code = ast_exec_string(input);
	}
	free(input);
	return (exit_code);
	(void)env;
}

int					builtin_env_exec(t_lst *tokens, t_shenv *env)
{
	int				exit_code;

	twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		shenv_print(env);
		exit_code = 0;
	}
	else
	{
		exit_code = exec_remaining_command(tokens, env);
	}
	return (exit_code);
}
