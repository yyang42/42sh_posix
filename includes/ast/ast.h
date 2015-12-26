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

# include "ast/nodes2/ast2_complete_command.h"
# include "tokenizer.h"

typedef struct		s_ast
{
	char						*raw;
	t_ast2_list					*root;
	t_parser					*parser;
	t_lst						*out_lines;
	int							out_depth;
	t_lst						*tokens;
	int							tokenpos;
	t_ast2_complete_command		*complete_command;
}					t_ast;

t_ast				*ast_new(char *input);
void				ast_del(t_ast *this);

char				*ast_str(t_ast *this);
void				ast_build2(t_ast *this);

void				ast_str_push_line(t_ast *ast, char *type, int index);

void				ast_print_tokens(t_ast *ast);

t_ast2_complete_command		*ast_build2_complete_command(t_ast *ast);
t_ast2_list 				*ast_build2_list(t_ast *ast, t_lst *tokens);

void						ast_str_append2_complete_command(t_ast *ast,
								t_ast2_complete_command *complete_command);
void						ast_str_append2_list(t_ast *ast, t_ast2_list *list);

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
