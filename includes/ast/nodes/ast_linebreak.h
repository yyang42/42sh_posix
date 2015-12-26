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

#ifndef AST_LINEBREAK_H
# define AST_LINEBREAK_H

# include "basics.h"

# include "token_mgr.h"
# include "ast/ast_utils.h"
# include "ast/nodes/ast_newline_list.h"

typedef struct		s_ast_linebreak
{
	t_lst			*tokens;
	t_ast_newline_list	*ast_newline_list;
}					t_ast_linebreak;

t_ast_linebreak			*ast_linebreak_new(void);
void				ast_linebreak_del(t_ast_linebreak *ast_linebreak);

t_ast_linebreak		*ast_linebreak_new_from_tokens(t_lst *tokens);
void				ast_linebreak_print_rec(t_ast_linebreak *ast_linebreak, int depth);

bool				ast_linebreak_is_own_type(t_lst *tokens);

#endif
