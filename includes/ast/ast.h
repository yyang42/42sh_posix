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

#ifndef AST_H
# define AST_H

# include "basics.h"

# include "parser.h"
# include "ast/ast_defines.h"

# include "ast/nodes/ast_compound_list.h"
# include "token/token_mgr.h"
# include "token/tokenizer.h"

typedef enum		e_ast_type
{
	AST_TYPE_LIST_ITEM = 0,
	AST_TYPE_ANDOR_ITEM,
	AST_TYPE_PIPE_ITEM,
	AST_TYPE_NBR,
}					t_ast_type;

typedef struct		s_ast
{
	t_lst						*tokens;
	t_ast_compound_list			*compound_list;
	char						*error_msg;
}					t_ast;

t_ast				*ast_new(char *input);
void				ast_del(t_ast *this);

void				ast_print_tokens(t_ast *ast);
void				ast_print_rec(t_ast *ast);

void				ast_set_error_msg_format(t_ast *ast, t_token *token, const char *fmt, ...);
void				ast_set_error_msg_syntax_error_near(t_ast *ast, t_token *token, char *msg);
void				ast_set_error_msg_syntax_error_missing(t_ast *ast, t_token *token, char *msg);

bool				ast_has_error(t_ast *this);
int					ast_exec(t_ast *ast);

#endif
