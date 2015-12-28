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

# include "token_mgr.h"
# include "ast/ast_utils.h"

typedef enum				s_redir_param_type
{
	IO_FILEHERE_FILE,
	IO_FILEHERE_HERE
}							t_redir_param_type;

typedef struct				s_ast_redir
{
	t_lst					*tokens;
	t_redir_param_type		type;
	int						io_number;
	char					*param;
}							t_ast_redir;

t_ast_redir	*ast_redir_new(void);
void				ast_redir_del(t_ast_redir *ast_redir);

t_ast_redir	*ast_redir_new_from_tokens(t_lst *tokens);
void				*ast_redir_new_from_tokens_void(t_lst *tokens);
void				ast_redir_print_rec(t_ast_redir *ast_redir, int depth);

bool				ast_redir_is_own_type(t_lst *tokens);

#endif
