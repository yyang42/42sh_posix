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
	t_token			*param;
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

void				ast_redir_print_function_list(t_lst *redir_items);

bool				ast_redir_is_own_type(t_lst *tokens);

bool				ast_redir_utils_is_heredoc(char *str);

#endif
