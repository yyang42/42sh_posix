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

# define REDIR_FD_FILE_FD_ERROR -1
# define REDIR_FD_FILE_FD_NOT_USED -2

typedef struct		s_ast_redir_fd
{
	int				fd_saved_std_fd;
	int				fd_origin;
	int				fd_file;
}					t_ast_redir_fd;

t_ast_redir_fd		*ast_redir_fd_new(void);
void				ast_redir_fd_del(t_ast_redir_fd *ast_redir_fd);
void				ast_redir_fd_del_void(t_ast_redir_fd *ast_redir_fd);
void				ast_redir_fd_handle_duplication(t_ast_redir_fd *redir_fd, t_ast_redir *redir, int default_fd);
int					ast_redir_fd_utils_heredoc_to_fd(t_ast_redir *redir);
void				ast_redir_fd_handle_input(t_ast_redir_fd *redir_fd, t_ast_redir *redir);
void				ast_redir_fd_handle_output(t_ast_redir_fd *redir_fd, t_ast_redir *redir);
void				ast_redir_fd_handle_agregation(t_ast_redir_fd *redir_fd, t_ast_redir *redir, t_lst *redir_fds);
void 				ast_redir_fd_utils_dup_fds(int fd1, int fd2);
int					ast_redir_fd_utils_get_duplication_fd(t_token *token);
bool				ast_redir_fd_utils_is_valid_duplicate_fd(int fd);
void				ast_redir_fd_init_save_origin(t_ast_redir_fd *redir_fd, t_ast_redir *redir, int default_fd);

#endif
