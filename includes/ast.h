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

# include "anode_compound_stmt.h"

# define AST_SEPARATOR_OP ";&"
# define AST_WHITE_SPACE "\t\n "

typedef struct				s_ast
{
	char					*raw;
	t_anode_compound_stmt	*root;
}							t_ast;

t_ast						*ast_new(char *input);
void						ast_del(t_ast *this);

void						ast_print(t_ast *this);

#endif
