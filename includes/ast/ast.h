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

# include "ast/ast_defines.h"

# include "ast/nodes/ast_compound_list.h"
# include "token/token_mgr.h"
# include "token/tokenizer.h"

# define AST_FLAG_NO_EXEC (1)

typedef enum		e_ast_type
{
	AST_TYPE_LIST_ITEM = 0,
	AST_TYPE_ANDOR_ITEM,
	AST_TYPE_PIPE_ITEM,
	AST_TYPE_NBR,
}					t_ast_type;

typedef struct		s_ast
{
	t_lst						*tokens_ref_tracker;
	t_ast_compound_list			*compound_list;
	char						*error_msg;
	t_lst						*ast_open_stack;
	int							ast_flags;
}					t_ast;

t_ast				*ast_new_from_string(char *input, int ast_flags);
t_ast				*ast_new(t_lst *src_tokens, int ast_flags);
void				ast_del(t_ast *this);

void				ast_print_tokens(t_ast *ast);
void				ast_print_rec(t_ast *ast);

void				ast_set_error_msg_format(t_ast *ast, const char *fmt, ...);
void				ast_set_error_msg_format_token(t_ast *ast, t_token *token, const char *fmt, ...);
void				ast_set_error_msg_syntax_error_near(t_ast *ast, t_token *token, char *msg);
void				ast_set_error_msg_syntax_error_missing(t_ast *ast, t_token *token, char *msg);
void				ast_set_error_msg_syntax_error_unexpected(t_ast *ast, t_token *token);

bool				ast_has_error(t_ast *this);

int					ast_expan(t_ast *ast);
void				ast_add_to_open_stack(t_ast *this, char *str);

char				*ast_utils_check_open(char *input);
bool				ast_utils_check_has_open(char *input);

void				ast_utils_exec_string(char *input);
int					ast_utils_try_exec_string(char *input);
void				ast_print_error(t_ast *ast);

#endif
