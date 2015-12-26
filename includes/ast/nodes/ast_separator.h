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

#ifndef AST_SEPARATOR_H
# define AST_SEPARATOR_H

# include "basics.h"

# include "token_mgr.h"
# include "ast/ast_utils.h"
# include "ast/nodes/ast_newline_list.h"
# include "ast/nodes/ast_separator_op.h"
# include "ast/nodes/ast_linebreak.h"

typedef enum		e_ast_separator_type
{
	AST_SEPERATOR_NONE,
	AST_SEPERATOR_NEWLINE_LIST,
	AST_SEPERATOR_SEPARATOR_OP
}					t_ast_separator_type;

typedef struct		s_ast_separator
{
	t_lst				*tokens;

	t_ast_separator_type type;
	t_ast_newline_list	*ast_newline_list;
	t_ast_separator_op	*ast_separator_op;
	t_ast_linebreak		*ast_linebreak;
}					t_ast_separator;

t_ast_separator		*ast_separator_new(void);
void				ast_separator_del(t_ast_separator *ast_separator);

t_ast_separator		*ast_separator_new_from_tokens(t_lst *tokens);
void				ast_separator_print_rec(t_ast_separator *ast_separator, int depth);

#endif
