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

#ifndef AST_SIMPLE_COMMAND_H
# define AST_SIMPLE_COMMAND_H

# include "basics.h"
# include "twl_stdlib.h"
# include "token/token_mgr.h"
# include "ast/ast_defines.h"
# include "ast/ast_utils.h"
# include "file.h"
# include "error.h"
# include "errno.h"
# include "signals.h"
# include "environment.h"
# include "ast/nodes/ast_redir.h"


typedef struct			s_ast_redir_fd
{
	int					fd_save;
	int					fd_origin;
	int					fd_file;
}						t_ast_redir_fd;

typedef struct			s_ast_simple_command
{
	t_lst				*command_tokens;
	t_lst				*redir_items;
	t_lst				*assignment_items;
	t_lst				*redir_fds;
	t_dict				*builtin_func;
}						t_ast_simple_command;


t_ast_simple_command	*ast_simple_command_new(void);
void					ast_simple_command_del(t_ast_simple_command *ast_s_cmd);
bool					ast_simple_command_check_files(t_ast_simple_command *t);
t_ast_simple_command	*ast_simple_command_new_from_tokens(t_lst *tokens,
	struct s_ast *ast);
t_ast_simple_command	*ast_simple_command_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void					ast_simple_command_print_rec(t_ast_simple_command
	*ast_s_cmd, int depth);

bool					ast_simple_command_is_own_type(t_lst *tokens);
int						ast_simple_command_exec(t_ast_simple_command *cmd);
bool					is_builtin(char *cmd);
char					*get_binary_path(char *cmd, t_environment *env);
void 					dup_fds(int fd1, int fd2);
bool					ast_simple_command_check_files(t_ast_simple_command *c);
void					ast_simple_command_redirs(t_ast_simple_command *cmd);
void					execute_simple_command(t_ast_simple_command *cmd,
	t_environment *env);
void					command_execution(char *path, char **args, char **env);
int						get_duplication_fd(char *str);
bool					is_valid_duplicate_fd(int fd);
t_dict					*get_builtin_func_dict(void);
int						duplication_input(t_ast_redir *redir,
	t_ast_redir_fd *redir_fd);
int						duplication_output(t_ast_redir *redir,
	t_ast_redir_fd *redir_fd);
int						write_heredoc_to_tmp_file(t_ast_redir *redir);
void					redir_input(t_ast_redir *redir,
	t_ast_redir_fd *redir_fd);
void					redir_output(t_ast_redir *redir,
	t_ast_redir_fd *redir_fd);
void					redir_input_output(t_ast_redir *redir,
	t_ast_redir_fd *redir_fd);
void					redir_agreg(t_ast_simple_command *cmd,
	t_ast_redir *redir, t_ast_redir_fd *redir_fd);
#endif
