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

typedef enum				s_io_filehere_type
{
	IO_FILEHERE_FILE,
	IO_FILEHERE_HERE
}							t_io_filehere_type;

typedef struct				s_ast_io_redirect
{
	t_lst					*tokens;
	int						io_number;
	t_io_filehere_type		type;
	void					*io_filehere;
}							t_ast_io_redirect;

t_ast_io_redirect	*ast_io_redirect_new(void);
void				ast_io_redirect_del(t_ast_io_redirect *ast_io_redirect);

t_ast_io_redirect	*ast_io_redirect_new_from_tokens(t_lst *tokens);
void				*ast_io_redirect_new_from_tokens_void(t_lst *tokens);
void				ast_io_redirect_print_rec(t_ast_io_redirect *ast_io_redirect, int depth);

bool				ast_io_redirect_is_own_type(t_lst *tokens);

#endif
