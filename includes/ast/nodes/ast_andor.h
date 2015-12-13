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

#ifndef AST_ANDOR_H
# define AST_ANDOR_H

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"

typedef enum		e_andor_type
{
	ANDOR_TYPE_AND,
	ANDOR_TYPE_OR
}					t_andor_type;

typedef struct		s_ast_andor
{
	t_ast_type			type;
	t_andor_type	andor_type;
	void			*left;
	void			*right;
}					t_ast_andor;

t_ast_andor				*ast_andor_new(t_andor_type andor_type);
void				ast_andor_del(t_ast_andor *this);

t_ast_andor				*ast_andor_build(char *str, int *len_ptr);

#endif
