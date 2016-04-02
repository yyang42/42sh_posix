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

#include "builtin/cmds/builtin_exec.h"
#include "file.h"
#include "logger.h"

static void			builtin_exec_execve_wrapper(char *path, char **argv, char **envp)
{
	if (!path)
	{
		shenv_singl_error(127, "exec: %s: not found", argv[0]);
	}
	else if (file_isdir(path) || !file_exists(path) || !file_isexecutable(path))
	{
		shenv_singl_error(126, "exec: %s: cannot execute", argv[0]);
	}
	else
	{
		execve(path, argv, envp);
	}
}

static void			builtin_exec_execve_prep(t_lst *remainders)
{
	char			*path;
	char			**argv;
	char			**envp;

	argv = (char **)twl_lst_to_arr(remainders);
	envp = (char **)shenv_get_env_arr(shenv_singleton());
	path = ast_simple_command_utils_get_binary_path(argv[0], shenv_singleton());
	builtin_exec_execve_wrapper(path, argv, envp);
	free(path);
	twl_arr_del(envp, free);
	twl_arr_del(argv, NULL);
}

void				builtin_exec_exec_do(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(builtin_exec_argparser(), tokens);
	env->shenv_cur_token = token_mgr_first(tokens);
	env->last_exit_code = EXIT_SUCCESS;
	if (argparser_result->err_msg)
	{
		argparser_result_print_usage_exit_status(argparser_result, 2);
	}
	else
	{
		if (twl_lst_len(argparser_result->remainders))
			builtin_exec_execve_prep(argparser_result->remainders);
	}
}

void				builtin_exec_exec(t_lst *tokens, t_shenv *env)
{
	t_lst			*redir_tokens_groups;
	t_lst			*remaining_of_redir_tokens;

	remaining_of_redir_tokens = twl_lst_new();
	redir_tokens_groups = token_mgr_extract_redir(tokens, remaining_of_redir_tokens);
	// token_mgr_print(tokens);
	// token_mgr_print(remaining_of_redir_tokens);
	builtin_exec_handle_redirs(redir_tokens_groups);
	builtin_exec_exec_do(remaining_of_redir_tokens, env);
}
