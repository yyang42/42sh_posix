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
# include "shsignal/shsignal.h"
# include "shenv/shenv.h"
# include "ast/nodes/ast_redir_mgr.h"
# include "ast/nodes/ast_redir_fd.h"
# include "ast/nodes/ast_redir_fd_mgr.h"
# include "ast/nodes/ast_simple_command_expan.h"
# include <pwd.h>

typedef struct			s_ast_simple_command
{
	t_lst				*all_tokens;
	t_lst				*cmd_tokens_deep_copy;
	t_lst				*cmd_tokens_expanded;
	t_lst				*redir_items;
	t_lst				*assignment_items;
	t_lst				*redir_fds;
}						t_ast_simple_command;

struct s_ast_compound_command;

t_ast_simple_command	*ast_simple_command_new(void);
void					ast_simple_command_del(t_ast_simple_command *ast_s_cmd);
bool					ast_simple_command_check_files(t_ast_simple_command *t);
t_ast_simple_command	*ast_simple_command_new_from_tokens(t_lst *tokens,
															struct s_ast *ast);
void					ast_simple_command_print_rec(
												t_ast_simple_command *ast_s_cmd,
												int depth);
void					ast_simple_command_print_function(
												t_ast_simple_command *ast_s_cmd,
												int depth);

bool					ast_simple_command_is_own_type(t_lst *tokens);
void					ast_simple_command_exec(t_ast_simple_command *cmd);
void					ast_simple_command_expan(t_ast_simple_command *cmd);

void					ast_simple_command_execve(t_lst *cmd_tokens,
															t_lst *all_tokens);
void					ast_simple_command_exec_tokens(
											t_ast_simple_command *ast_s_cmd);

void					ast_simple_command_exec_function(t_lst *tokens,
								struct s_ast_compound_command *compound_cmd);
void					ast_simple_command_execve_child(t_lst *cmd_tokens,
															char *path);
void					ast_simple_command_execve_parent(t_lst *all_tokens,
															pid_t pid);

bool					ast_simple_command_is_special_builtin(
													t_ast_simple_command *this);

#endif
