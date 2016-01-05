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
//
// static void	use_builtin(t_simple_command *cmd, char *builtin, char *string)
// {
// 	void *func;
// 	void (*f)(char *str);
//
// 	func = twl_dict_get(cmd->builtin_func, builtin);
// 	if (func)
// 	{
// 		f = func;
// 		f(string);
// 	}
// }
//
// static void  execute_builtin_no_redirect(t_simple_command *cmd, t_ast_cmd *ast_cmd, char *builtin)
// {
// 	char	*tmp;
//
// 	tmp = concatenate_ast_cmd(ast_cmd->strings);
// 	use_builtin(cmd, builtin, tmp);
// 	free(tmp);
// }
//
// static void  execute_builtin_redirect_in(t_simple_command *cmd, t_ast_cmd *ast_cmd, char *builtin)
// {
// 	char	*file_name;
// 	int		fd;
// 	int		save_stdin;
//
// 	file_name = get_redir_in_file_name_from_ast_cmd(ast_cmd);
// 	if (file_name)
// 	{
// 		fd = read_file(file_name);
// 		if (fd >= 0)
// 		{
// 			save_stdin = dup(STDIN_FILENO);
// 			dup_fds(fd, STDIN_FILENO);
// 			execute_builtin_no_redirect(cmd, ast_cmd, builtin);
// 			close_file(fd);
// 			dup2(save_stdin, STDIN_FILENO);
// 		}
// 	}
// }
//
// static void  execute_builtin_redirect_out(t_simple_command *cmd, t_ast_cmd *ast_cmd, char *builtin)
// {
// 	char	*file_name;
// 	int		fd;
// 	int		save_stdout;
//
// 	file_name = get_redir_out_file_name_from_ast_cmd(ast_cmd);
// 	if (file_name)
// 	{
// 		fd = create_file(file_name);
// 		if (fd >= 0)
// 		{
// 			save_stdout = dup(STDOUT_FILENO);
// 			dup_fds(fd, STDOUT_FILENO);
// 			execute_builtin_no_redirect(cmd, ast_cmd, builtin);
// 			close_file(fd);
// 			dup2(save_stdout, STDOUT_FILENO);
// 		}
// 	}
// }
//
// void		execute_builtin(t_simple_command *cmd, t_ast_cmd *ast_cmd, char *path)
// {
// 	if (twl_lst_len(ast_cmd->redir_in) > 0 && (twl_lst_len(ast_cmd->redir_out) > 0))
// 	{
// 		execute_builtin_redirect_in(cmd, ast_cmd, path);
// 		execute_builtin_redirect_out(cmd, ast_cmd, path);
// 	}
// 	else if (twl_lst_len(ast_cmd->redir_in) > 0)
// 		execute_builtin_redirect_in(cmd, ast_cmd, path);
// 	else if (twl_lst_len(ast_cmd->redir_out) > 0)
// 		execute_builtin_redirect_out(cmd, ast_cmd, path);
// 	else if (path)
// 		execute_builtin_no_redirect(cmd, ast_cmd, path);
// }
