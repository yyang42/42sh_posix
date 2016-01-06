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

void		ast_redirect_in(t_ast_simple_command *cmd)
{
	(void)cmd;
	// int				fd;
	// char			*file_name;
	// char			**args;
	// char			**env;
	// int				save_stdin;
	//
	// file_name = get_redir_in_file_name_from_ast_command(ast_cmd);
	// if (file_name)
	// {
	// 	twl_printf("fn1: %s\n", binary_path);
	// 	fd = read_file(file_name);
	// 	if (fd >= 0 && binary_path)
	// 	{
	// 		save_stdin = dup(0);
	// 		args = get_cmd_args_from_ast_cmd(ast_cmd, binary_path);
	// 		dup_fds(fd, 0);
	// 		env = environment_get_env_arr(environment_singleton());
	// 		command_execution(binary_path, args, env);
	// 		close_file(fd);
	// 		dup2(save_stdin, 0);
	// 	}
	// }
}
