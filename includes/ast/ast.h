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
# include "ast/nodes/ast_cmd_field.h"
# include "ast/nodes/ast_node.h"

typedef struct		s_ast
{
	char			*raw;
	t_ast_list		*root;
	t_parser		*parser;
}					t_ast;

t_ast				*ast_new(char *input);
void				ast_del(t_ast *this);

char				*ast_to_str(t_ast *this);
char				*ast_to_str2(t_ast *this);
void				ast_build(t_ast *this);
void				ast_build2(t_ast *this);

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
