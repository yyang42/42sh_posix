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

#ifndef AST_IO_REDIRECT_H
# define AST_IO_REDIRECT_H

# include "basics.h"

# include "token/token_mgr.h"

# include "file.h"
# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

# define IO_NUMBER_NOT_DEFINED -1

typedef struct		s_ast_redir
{
	t_lst			*redir_tokens;
	int				io_number;
	char			*operator;
	char			*param;
	char			*param_unexpanded;
	char			*heredoc_text;
	char			*heredoc_text_unexpanded;
}					t_ast_redir;

t_ast_redir			*ast_redir_new(t_lst *tokens);
void				ast_redir_del(t_ast_redir *ast_redir);
void				ast_redir_del_void(t_ast_redir *this);

t_ast_redir			*ast_redir_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void				*ast_redir_new_from_tokens_void(t_lst *tokens, struct s_ast *ast);
void				ast_redir_print_rec(t_ast_redir *ast_redir, int depth);
void				ast_redir_print_rec_list(t_lst *redir_items, int depth);

bool				ast_redir_is_own_type(t_lst *tokens);

void 				ast_redir_fd_utils_dup_fds(int fd1, int fd2);
int					ast_redir_fd_utils_get_duplication_fd(char *str);
bool				ast_redir_fd_utils_is_valid_duplicate_fd(int fd);

#endif
