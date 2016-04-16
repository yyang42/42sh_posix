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

#ifndef AST_REDIR_FD_H
# define AST_REDIR_FD_H

# include "basics.h"
# include "ast/nodes/ast_redir.h"

typedef struct		s_ast_redir_fd
{
	int					fd_save;
	int					fd_origin;
	int					fd_file;
}					t_ast_redir_fd;

t_ast_redir_fd			*ast_redir_fd_new(void);
void					ast_redir_fd_del(t_ast_redir_fd *ast_redir_fd);

int						ast_redir_fd_duplication_input(t_ast_redir *redir, t_ast_redir_fd *redir_fd);
int						ast_redir_fd_duplication_output(t_ast_redir *redir, t_ast_redir_fd *redir_fd);
int						ast_redir_fd_write_heredoc_to_tmp_file(t_ast_redir *redir);
void					ast_redir_fd_redir_input(t_ast_redir *redir, t_ast_redir_fd *redir_fd);
void					ast_redir_fd_redir_output(t_ast_redir *redir, t_ast_redir_fd *redir_fd);
void					ast_redir_fd_redir_input_output(t_ast_redir *redir, t_ast_redir_fd *redir_fd);
void					ast_redir_fd_redir_agreg(t_ast_redir *redir, t_lst *redir_fds, t_ast_redir_fd *redir_fd);

void 					ast_redir_fd_utils_dup_fds(int fd1, int fd2);
int						ast_redir_fd_utils_get_duplication_fd(t_token *token);
bool					ast_redir_fd_utils_is_valid_duplicate_fd(int fd);

#endif
