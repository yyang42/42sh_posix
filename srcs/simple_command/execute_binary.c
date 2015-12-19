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

#include "simple_command.h"

static void execute_binary_redirect_in(t_ast_cmd *ast_cmd, char *binary_path)
{
	int				fd;
	char			*file_name;
	char			**args;
	char			**env;
	int				save_stdin;

	file_name = get_redir_in_file_name_from_ast_cmd(ast_cmd);
	if (file_name)
	{
		twl_printf("fn1: %s\n", binary_path);
		fd = read_file(file_name);
		if (fd >= 0 && binary_path)
		{
			save_stdin = dup(0);
			args = get_cmd_args_from_ast_cmd(ast_cmd, binary_path);
			dup_fds(fd, 0);
			env = environment_get_env_arr(environment_singleton());
			command_execution(binary_path, args, env);
			close_file(fd);
			dup2(save_stdin, 0);
		}
	}
}

static void execute_binary_redirect_out(t_ast_cmd *ast_cmd, char *binary_path)
{
	int				fd;
	char			*file_name;
	char			**args;
	char			**env;
	int				save_stdout;

	file_name = get_redir_out_file_name_from_ast_cmd(ast_cmd);
	if (file_name)
	{
		twl_printf("fn2: %s\n", binary_path);
		fd = create_file(file_name);
		if (fd >= 0  && binary_path)
		{
			save_stdout = dup(1);
			args = get_cmd_args_from_ast_cmd(ast_cmd, binary_path);
			dup_fds(fd, 1);
			env = environment_get_env_arr(environment_singleton());
			command_execution(binary_path, args, env);
			close_file(fd);
			dup2(save_stdout, 1);
		}
	}
}

static void execute_binary_redirect_in_out(t_ast_cmd *ast_cmd, char *binary_path)
{
	int				fd;
	int				fd2;
	char			*file_name;
	char			*file_name2;
	char			**args;
	char			**env;
	int				save_stdin;
	int				save_stdout;

	file_name = get_redir_in_file_name_from_ast_cmd(ast_cmd);
	file_name2 = get_redir_out_file_name_from_ast_cmd(ast_cmd);
	if (file_name && file_name2)
	{
		fd = read_file(file_name);
		fd2 = create_file(file_name2);
		if (fd >= 0 && fd2 >= 0 && binary_path)
		{
			save_stdin = dup(STDIN_FILENO);
			save_stdout = dup(STDOUT_FILENO);
			args = get_cmd_args_from_ast_cmd(ast_cmd, binary_path);
			dup_fds(fd, STDIN_FILENO);
			dup_fds(fd2, STDOUT_FILENO);
			env = environment_get_env_arr(environment_singleton());
			command_execution(binary_path, args, env);
			close_file(fd);
			close_file(fd2);
			dup2(save_stdin, STDIN_FILENO);
			dup2(save_stdout, STDOUT_FILENO);
		}
	}
}

static void execute_binary_no_redirect(t_ast_cmd *ast_cmd, char *binary_path)
{
	char			**args;
	char			**env;

	args = get_cmd_args_from_ast_cmd(ast_cmd, binary_path);
	env = environment_get_env_arr(environment_singleton());
	command_execution(binary_path, args, env);
}

void		execute_binary(t_ast_cmd *ast_cmd, char *path)
{
	if (twl_lst_len(ast_cmd->redir_in) > 0 && (twl_lst_len(ast_cmd->redir_out) > 0))
		execute_binary_redirect_in_out(ast_cmd, path);
	else if (twl_lst_len(ast_cmd->redir_in) > 0)
		execute_binary_redirect_in(ast_cmd, path);
	else if (twl_lst_len(ast_cmd->redir_out) > 0)
		execute_binary_redirect_out(ast_cmd, path);
	else if (path)
		execute_binary_no_redirect(ast_cmd, path);
}
