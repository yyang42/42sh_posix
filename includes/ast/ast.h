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

# include "ast/nodes/ast_complete_command.h"
# include "token_mgr.h"
# include "tokenizer.h"

typedef struct		s_ast
{
	t_lst						*tokens;
	t_ast_complete_command		*complete_command;
}					t_ast;

t_ast				*ast_new(char *input);
void				ast_del(t_ast *this);

void				ast_print_tokens(t_ast *ast);
void				ast_print_rec(t_ast *ast);

#endif
