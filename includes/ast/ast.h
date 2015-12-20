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
# include "ast/nodes/ast_list.h"
# include "ast/nodes/ast_if.h"
# include "ast/nodes/ast_cmd.h"
# include "ast/nodes/ast_simple_cmd.h"
# include "ast/nodes/ast_cmd_subshell.h"
# include "ast/nodes/ast_cmd_field.h"
# include "ast/nodes/ast_node.h"
# include "ast/nodes/ast_andor_seq.h"
# include "ast/nodes/ast_pipe_seq.h"

typedef struct		s_ast
{
	char			*raw;
	t_ast_list		*root;
	t_parser		*parser;
	t_lst			*out_lines;
	int				out_depth;
}					t_ast;

t_ast				*ast_new(char *input);
void				ast_del(t_ast *this);

char				*ast_str(t_ast *this);
void				ast_build(t_ast *this);

t_ast_list			*ast_build_list(t_ast *ast);
t_ast_andor_seq			*ast_build_andor_seq(t_ast *ast);
t_ast_pipe_seq			*ast_build_pipe(t_ast *ast);
void				*ast_build_cmd(t_ast *ast);
t_ast_cmd_subshell	*ast_build_cmd_subshell(t_ast *ast);
t_ast_simple_cmd	*ast_build_simple_cmd(t_ast *ast);

void				ast_str_append_list(t_ast *ast, t_ast_list *list);
void				ast_str_append_andor_seq(t_ast *ast, t_ast_andor_seq *andor);
void				ast_str_append_pipe(t_ast *ast, t_ast_pipe_seq *pipe);
void				ast_str_append_cmd(t_ast *ast, t_ast_cmd *cmd);
void				ast_str_append_simple_cmd(t_ast *ast, void *cmd);
void				ast_str_append_cmd_subshell(t_ast *ast, void *cmd_);
void				ast_str_push_line(t_ast *ast, char *type, int index);

/*

list      			// ; & \n
andor_seq			// && ||
pipe_seq			// |
command
	brace_group
	subshell
	for_clause
	case_clause
	if_clause
	while_clause
	until_clause

if
	list

*/

#endif
